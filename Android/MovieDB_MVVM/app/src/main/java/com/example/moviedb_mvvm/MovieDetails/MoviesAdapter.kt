package com.example.moviedb_mvvm.MovieDetails

import android.graphics.Movie
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.view.ViewParent
import android.widget.ImageView
import androidx.recyclerview.widget.RecyclerView
import com.bumptech.glide.Glide
import com.bumptech.glide.load.resource.bitmap.CenterCrop
import com.example.moviedbmvvm.R

class MoviesAdapter(
        //We changed the type of the movies variable to MutableList because we now have a dynamic list of movies.
        //Earlier we have used List instead List instead MutableList
        private var movies: MutableList<Movies>,
        private val onMovieClick: (movie: Movies) -> Unit
) : RecyclerView.Adapter<MoviesAdapter.MovieViewHolder>() {

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): MovieViewHolder {
        val view = LayoutInflater
                .from(parent.context)
                .inflate(R.layout.item_movie, parent, false)
        return MovieViewHolder(view)
    }



    fun appendMovies(movies: List<Movies>){
        this.movies.addAll(movies)
        //We use notifyItemRangeInserted instead of notifydatasetchnage() because dont want to refresh the whole list.
        //we just to update start and end point.
        notifyItemRangeInserted(
                this.movies.size,
                movies.size - 1
        )
    }

    override fun getItemCount (): Int = movies.size

    override fun onBindViewHolder(holder: MovieViewHolder, position: Int) {
        holder.bind(movies[position])
    }

    fun updateMovies(movies: List<Movies>) {
        this.movies = movies as MutableList<Movies>
        notifyDataSetChanged()
    }

    inner class MovieViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView) {

         val poster: ImageView = itemView.findViewById(R.id.item_movie_poster)

        fun bind(movie: Movies) {
            Glide.with(itemView)
                    .load("https://image.tmdb.org/t/p/w342${movie.posterPath}")
                    .transform(CenterCrop())
                    .into(poster)

            itemView.setOnClickListener{onMovieClick.invoke(movie)}
        }
    }
}
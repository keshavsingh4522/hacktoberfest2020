package com.example.moviedb_mvvm.MovieDetails

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.widget.Toast
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView
import com.example.moviedbmvvm.R
import kotlinx.android.synthetic.main.activity_movie_details.*

class MainActivity : AppCompatActivity() {

    //Popular Movies
    private lateinit var popularMovies: RecyclerView
    private lateinit var popularMoviesAdapter: MoviesAdapter
    private lateinit var popularMoviesLayoutMgr: LinearLayoutManager
    private var popularMoviesPage = 1

    //For Top Rated
    private lateinit var topRatedMovies: RecyclerView
    private lateinit var topRatedMoviesAdapter: MoviesAdapter
    private lateinit var topRatedMoviesLayoutMgr:  LinearLayoutManager
    var topRatedMoviesPage = 1

    private lateinit var upcomingMovies: RecyclerView
    private lateinit var upcomingMoviesAdapter: MoviesAdapter
    private lateinit var upcomingMoviesLayoutMgr: LinearLayoutManager

    private var upcomingMoviesPage = 1


    //In Oncreate() , instantiate popularMoviesLayoutMgr variable, assign it to popularMovie Recycler View,
    //pass popularMoviepage to MoviesRepository.getPopularMovies() , and empty MutableList in MovieAdopter
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        //popular Movies

        popularMovies = findViewById(R.id.popular_movies)
        popularMoviesLayoutMgr = LinearLayoutManager(
                this,
                LinearLayoutManager.HORIZONTAL,
                false
        )
        popularMovies.layoutManager = popularMoviesLayoutMgr
        popularMoviesAdapter = MoviesAdapter(mutableListOf()) { movie -> showMovieDetails(movie) }
        popularMovies.adapter = popularMoviesAdapter



        //Top Rated Movies

        topRatedMovies = findViewById(R.id.top_rated_movies)
        topRatedMoviesLayoutMgr = LinearLayoutManager(
                this,
                LinearLayoutManager.HORIZONTAL,
                false
        )
        topRatedMovies.layoutManager = topRatedMoviesLayoutMgr
        topRatedMoviesAdapter = MoviesAdapter(mutableListOf()) { movie -> showMovieDetails(movie) }
        topRatedMovies.adapter = topRatedMoviesAdapter


        //upcomming movies

        upcomingMovies = findViewById(R.id.upcoming_movies)
        upcomingMoviesLayoutMgr = LinearLayoutManager(
                this,
                LinearLayoutManager.HORIZONTAL,
                false
        )
        upcomingMovies.layoutManager = upcomingMoviesLayoutMgr
        upcomingMoviesAdapter = MoviesAdapter(mutableListOf()) { movie -> showMovieDetails(movie) }
        upcomingMovies.adapter = upcomingMoviesAdapter


        getPopularMovies()
        getTopRatedMovies()
        getUpcomingMovies()


        }

    private fun showMovieDetails(movie: Movies){
        val intent = Intent(this, MovieDetailsActivity::class.java)
        intent.putExtra(MOVIE_BACKDROP, movie.backdropPath)
        intent.putExtra(MOVIE_POSTER, movie.posterPath)
        intent.putExtra(MOVIE_TITLE, movie.title)
        intent.putExtra(MOVIE_RATING, movie.rating)
        intent.putExtra(MOVIE_RELEASE_DATE, movie.releaseDate)
        intent.putExtra(MOVIE_OVERVIEW, movie.overview)
        startActivity(intent)
    }



    private fun getPopularMovies() {
        MoviesRepository.getPopularMovies(
                popularMoviesPage,
                ::onPopularMoviesFetched,
                ::onError
        )
    }

    private fun getUpcomingMovies() {
        MoviesRepository.getUpcomingMovies(
                upcomingMoviesPage,
                ::onUpcomingMoviesFetched,
                ::onError
        )
    }


    //if the popular movies are fetched
    private fun onPopularMoviesFetched(movies: List<Movies>) {
        popularMoviesAdapter.appendMovies(movies)
        attachPopularMoviesOnScrollListener()
    }

    private fun getTopRatedMovies(){
        MoviesRepository.getTopRatedMovies(
                topRatedMoviesPage,
                ::onTopRatedMoviesFetched,
                ::onError
        )
    }

    private fun onUpcomingMoviesFetched(movies: List<Movies>) {
        upcomingMoviesAdapter.appendMovies(movies)
        attachUpcomingMoviesOnScrollListener()
    }

    private fun onTopRatedMoviesFetched(movies: List<Movies>) {
        topRatedMoviesAdapter.appendMovies(movies)
        attachTopRatedMoviesOnScrollListener()
    }



    private fun attachPopularMoviesOnScrollListener(){
        popularMovies.addOnScrollListener(object : RecyclerView.OnScrollListener(){
            override fun onScrolled(recyclerView: RecyclerView, dx: Int, dy: Int) {
                // totalItemClient - is thr totoal number of movies inside popularmoviesAdapter. This will keep increasing the
                // more we call popularMoviesAdapter.appendMovies()
                val totalItemCount = popularMoviesLayoutMgr.itemCount
                // visibleItemCount - the current number of child views attached to the RecyclerView that are currently being
                // recycled over and over again. The value of this variable for common screen sizes will range roughly around
                // 4-5 which are 3 visible views, +1 left view that’s not seen yet and +1 right view that’s not seen yet also.
                // The value will be higher if you have a bigger screen.
                val visibleItemCount = popularMoviesLayoutMgr.childCount

                // firstVisibleItem - is the position of the leftmost visible item in our list.
                val firstVisibleItem = popularMoviesLayoutMgr.findFirstVisibleItemPosition()

                // The condition will be true if the user has scrolled past halfway plus a buffered value of visibleItemCount.
                if(firstVisibleItem + visibleItemCount >= totalItemCount / 2 ){
                    //After condition is met, we disable the scroll listener since we only want this code to run once.
                        // Next, we increment popularMoviesPage and then call getPopularMovies().
                    Log.d("MainActivity", "Fetching movies")
                    popularMoviesPage++
                    getPopularMovies()
                }
            }
        })
    }
    //if Error encountered
    private fun  onError(){
        Toast.makeText(this, getString(R.string.error_fetch_movies), Toast.LENGTH_SHORT).show()

    }

    private fun attachTopRatedMoviesOnScrollListener() {
        topRatedMovies.addOnScrollListener(object : RecyclerView.OnScrollListener() {
            override fun onScrolled(recyclerView: RecyclerView, dx: Int, dy: Int) {
                val totalItemCount = topRatedMoviesLayoutMgr.itemCount
                val visibleItemCount = topRatedMoviesLayoutMgr.childCount
                val firstVisibleItem = topRatedMoviesLayoutMgr.findFirstVisibleItemPosition()

                if (firstVisibleItem + visibleItemCount >= totalItemCount / 2) {
                    Log.d("MainActivity", "Fetching movies")

                    topRatedMoviesPage++
                    getTopRatedMovies()
                }
            }
        })
    }

    private fun attachUpcomingMoviesOnScrollListener() {
        upcomingMovies.addOnScrollListener(object : RecyclerView.OnScrollListener() {
            override fun onScrolled(recyclerView: RecyclerView, dx: Int, dy: Int) {
                val totalItemCount = upcomingMoviesLayoutMgr.itemCount
                val visibleItemCount = upcomingMoviesLayoutMgr.childCount
                val firstVisibleItem = upcomingMoviesLayoutMgr.findFirstVisibleItemPosition()

                if (firstVisibleItem + visibleItemCount >= totalItemCount / 2) {
                    upcomingMovies.removeOnScrollListener(this)
                    upcomingMoviesPage++
                    getUpcomingMovies()
                }
            }
        })
    }
}
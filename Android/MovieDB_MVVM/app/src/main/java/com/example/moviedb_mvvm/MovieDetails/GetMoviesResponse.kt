package com.example.moviedb_mvvm.MovieDetails

import android.graphics.Movie
import com.google.gson.annotations.SerializedName

data class GetMoviesResponse(
    @SerializedName("page") val page: Int,
    @SerializedName("results") val movies: List<Movies>,
    @SerializedName("total_pages") val pages: Int
)

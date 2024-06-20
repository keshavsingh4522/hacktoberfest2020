package com.example.moviedb_mvvm.MovieDetails

import retrofit2.Call
import retrofit2.http.GET
import retrofit2.http.Query

interface Api {
    //For Popular Movies
    @GET("movie/popular")
    fun getPopularMovies(
        @Query("api_key") apiKey: String = "db5a02836ac059ccd549ca97acec9d1a",
        @Query("page") page: Int
    ): Call<GetMoviesResponse>

    //For Top Rated Movies
    @GET("movie/top_rated")
    fun getTopRatedMovies(
            @Query("api_key") apiKey: String = "db5a02836ac059ccd549ca97acec9d1a",
            @Query("pages") page: Int
    ): Call<GetMoviesResponse>

    //for Upcoming movie
    @GET("movie/upcoming")
    fun getUpcomingMovies(
            @Query("api_key") apiKey: String = "db5a02836ac059ccd549ca97acec9d1a",
            @Query("page") page: Int
    ): Call<GetMoviesResponse>
}
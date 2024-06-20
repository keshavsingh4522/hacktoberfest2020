package com.example.moviedb_mvvm.MovieDetails

import retrofit2.Call
import retrofit2.Callback
import retrofit2.Response
import retrofit2.Retrofit
import retrofit2.converter.gson.GsonConverterFactory
import kotlin.reflect.KFunction1


object MoviesRepository {
    private val api: Api

    init {
            val retrofit = Retrofit.Builder()
                .baseUrl("https://api.themoviedb.org/3/")
                .addConverterFactory(GsonConverterFactory.create())
                .build()

        api = retrofit.create(Api::class.java)
    }

    //Funcion for Popular Movies
    fun getPopularMovies(page: Int = 1,
                         onSuccess: (movies: List<Movies>) -> Unit,
                         onError: () -> Unit
    ) {
        api.getPopularMovies(page = page)
            .enqueue(object : Callback<GetMoviesResponse> {
                override fun onResponse(
                    call: Call<GetMoviesResponse>,
                    response: Response<GetMoviesResponse>
                ) {
                    if (response.isSuccessful) {
                        val responseBody = response.body()

                        if (responseBody != null) {
                            onSuccess.invoke(responseBody.movies)
                        } else {
                            onError.invoke()
                        }
                    }
                }

                override fun onFailure(call: Call<GetMoviesResponse>, t: Throwable) {
                    onError.invoke()
                }
            })
    }

    //Function for Toprated
    fun getTopRatedMovies(
            page: Int = 1,
            onSuccess: (movies: List<Movies>) -> Unit,
            onError: () -> Unit
    ) {
        api.getTopRatedMovies(page = page)
                .enqueue(object : Callback<GetMoviesResponse>{
                    override fun onResponse(
                            call: Call<GetMoviesResponse>,
                            response: Response<GetMoviesResponse>)
                    {
                        if (response.isSuccessful){
                            val responseBody = response.body()
                            if (responseBody != null) {
                                onSuccess.invoke(responseBody.movies)
                            } else {
                                onError.invoke()
                            }
                        }
                    }

                    override fun onFailure(call: Call<GetMoviesResponse>, t: Throwable) {
                        onError.invoke()
                    }
                })
    }

    fun getUpcomingMovies(
            page: Int = 1,
            onSuccess: (movies:List<Movies>) -> Unit,
            onError: () -> Unit
    ) {
        api.getUpcomingMovies(page = page)
                .enqueue(object : Callback<GetMoviesResponse> {
                    override fun onResponse(
                            call: Call<GetMoviesResponse>,
                            response: Response<GetMoviesResponse>
                    ) {
                        if (response.isSuccessful) {
                            val responseBody = response.body()

                            if (responseBody != null) {
                                onSuccess.invoke(responseBody.movies)
                            } else {
                                onError.invoke()
                            }
                        } else {
                            onError.invoke()
                        }
                    }

                    override fun onFailure(call: Call<GetMoviesResponse>, t: Throwable) {
                        onError.invoke()
                    }
                })
    }
}
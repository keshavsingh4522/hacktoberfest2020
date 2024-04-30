import articles from "../apis/articles";

export const fetchArticles = () =>
    async dispatch=>{
    const response = await articles.post('/ArticleService/getArticleListing',
    {},
    {
      headers: {
        Authorization: `Bearer ${localStorage.getItem("token")}`,
      },
    })
   dispatch({type:'FETCH_ARTICLES',payload:response.data.result.article})
    };

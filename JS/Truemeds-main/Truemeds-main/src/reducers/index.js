import { combineReducers } from "redux";
import articlesReducer from "./articlesReducer";
export default combineReducers({
    articles:articlesReducer
});
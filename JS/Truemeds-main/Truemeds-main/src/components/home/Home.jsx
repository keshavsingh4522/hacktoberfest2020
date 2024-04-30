import React, { useEffect, useState } from "react";
import Button from "@mui/material/Button";
import { useHistory } from "react-router-dom";
import { connect } from "react-redux";
import { fetchArticles } from "../../actions";
import Articles from "../articles/Articles";

const Home = (props) => {
  console.log(props);
  const { initialMinute = 1, initialSeconds = 0 } = props;
  const [minutes, setMinutes] = useState(initialMinute);
  const [seconds, setSeconds] = useState(initialSeconds);
  let history = useHistory();
  const fetch = () => {
    props.fetchArticles();
  };
  useEffect(() => {
    let myInterval = setInterval(() => {
      if (seconds > 0) {
        setSeconds(seconds - 1);
      }
      if (seconds === 0) {
        if (minutes === 0) {
          fetch();
          console.log("first");
          clearInterval(myInterval);
        } else {
          setMinutes(minutes - 1);
          setSeconds(59);
        }
      }
    }, 1000);
    return () => {
      clearInterval(myInterval);
    };
  }, [minutes, seconds]);

  const reset = () => {
    setMinutes(1);
  };

  const logout = () => {
    localStorage.removeItem("token");
    props.logout();
    history.push("/login");
  };
  if (!props.loggedIn) history.push("/login");
  return (
    <div className="container">
      <br />
      <Button variant="contained" onClick={logout}>
        Logout
      </Button>
      {minutes === 0 && seconds === 0 ? (
        <div>
          <Button variant="contained" onClick={reset}>
            Reset Timer
          </Button>
          {props.articles &&
            props.articles.map((item) => (
              <Articles
                key={item.id}
                name={item.name}
                author={item.author}
                category={item.categoryName}
              ></Articles>
            ))}
        </div>
      ) : (
        <h1>
          {" "}
          {minutes}:{seconds < 10 ? `0${seconds}` : seconds}
        </h1>
      )}
    </div>
  );
};

const mapStateToProps = (state) => {
  return { articles: state.articles };
};
export default connect(mapStateToProps, { fetchArticles })(Home);

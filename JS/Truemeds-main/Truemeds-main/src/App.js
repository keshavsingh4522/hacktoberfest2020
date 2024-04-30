import { BrowserRouter as Router, Route, Switch  } from "react-router-dom";
import Login from './components/login/login';
import './App.css';
import Home from "./components/home/Home";
import { useState } from "react";

function App() {
  const [loggedin, setloggedin] = useState(false)
  const success=()=>setloggedin(true);
  const logout=()=>setloggedin(false);
  return (
    <div className="App">
      <Router>
      <Switch >
      <Route exact path="/login" component={() =><Login  success={success}/>} />
      <Route exact path="/" component={() =><Home loggedIn={loggedin} logout={logout}/>} />
      </Switch ></Router>
    </div>
  );
}

export default App;

import React,{Component} from "react";
import './App.css';
import {CardList} from "./components/card-list/card-list"
import { SearchBox } from "./components/search-box/search-box";

class App extends Component {
  constructor(){
    super();

    this.state={
      monsters: [],
      searchField: ""
    };
  }

  componentDidMount() {
    fetch("https://jsonplaceholder.typicode.com/users")
    .then(response => response.json())
    .then(users=>this.setState({monsters: users}));
  }

  render(){
    const {monsters,searchField} = this.state;
    const filteredmonsters = monsters.filter(monster=>
      monster.name.toLowerCase().includes(searchField.toLowerCase())
    );
    return (
      <div className="App">
      <h1>Monsters Rolodex</h1>
      <SearchBox placeholder="search monsters" handleChange={e=>this.setState({searchField:e.target.value})}/>
      <CardList monsters = {filteredmonsters} />
      </div>
    );
  }
}

export default App;

import React from 'react'
import { useHistory } from "react-router-dom";

function Logout(props) {
    let history = useHistory();
    function loggout(){
        localStorage.removeItem('token')
    props.logout();
        }
        loggout();
    history.push('/login');
    

    return (
        <div>
            
        </div>
    )
}

export default Logout

import axios from "axios";

export default axios.create({
    baseURL: 'https://stage-services.truemeds.in'
})
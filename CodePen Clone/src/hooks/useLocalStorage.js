import {useEffect,useState} from 'react'
const PREFIX = 'codepen-clone-'

function useLocalStorage(key, initialValue) {
    const PREFIXEDKEY = PREFIX + key;
    const [value, setvalue] = useState(()=>{
        const jsonValue = localStorage.getItem(PREFIXEDKEY)
        if(jsonValue!=null)return JSON.parse(jsonValue)
        if(typeof initialValue === 'function'){
            return initialValue();
        }else{
            return initialValue;
        }
    })
    useEffect(() => {
       localStorage.setItem(PREFIXEDKEY, JSON.stringify(value))
    }, [PREFIXEDKEY, value])
    return [value,setvalue]
}

export default useLocalStorage

import Editor from "./Editor";
import React, {useState, useEffect} from 'react'
import useLocalStorage from '../hooks/useLocalStorage'

function App() {

  const [html, sethtml] = useLocalStorage('html','')
  const [css, setcss] = useLocalStorage('css','')
  const [js, setjs] = useLocalStorage('js','')
  const [SrcDoc, setSrcDoc] = useState('')

  useEffect(() => {
    const timeOut =setTimeout(()=>{
      setSrcDoc(`<html>
      <body>${html}</body>
      <style>${css}</style>
      <script>${js}</script>
    </html>`)
    }, 250)
    return ()=>{
      clearTimeout(timeOut)
    }
  }, [html,css,js])

  return (
    <>
    <div className="pane top-pane">
      <Editor language='xml' displayName="HTML" value={html} onChange={sethtml} /*HTML code editor*//>  
      <Editor language='css' displayName="CSS" value={css} onChange={setcss} /*CSS code editor*//>
      <Editor language='javascript' displayName="JS" value={js} onChange={setjs} /*JS code editor*//>
    </div>
    <div className="pane">
      <iframe
        srcDoc={SrcDoc}
        title="OUTPUT"
        sandbox="allow-scripts"
        frameBorder="0"
        width="100%"
        height="100%"
      />
    </div>
    </>
  );
}

export default App;

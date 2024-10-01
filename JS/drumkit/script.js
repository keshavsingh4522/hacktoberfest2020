
window.addEventListener("keydown", function (e) {
    console.log(e.keyCode);
    const audio = document.querySelector(`audio[data-key="${e.keyCode}"]`);
    if (!audio) return;
    audio.play();
    console.log(audio);
});
// Math.floor(Math.random() * (max - min)) + min;

var num=0;
var r_gs , g_gs , b_gs;
var active_btn = false;
var score = 0.0;
var turn = 0;
var chances = 0;

var col_head = "rgb(130, 120, 180)";

function restart(){
	if(active_btn) return;
	turn++;
	chances=0;
	
	active_btn=true;
	
	var max=255;
	var min=0;
	// reset the heading color
	document.getElementById("to_guess")
	.style.backgroundColor=col_head;

	// reset to guess color
	r_gs=Math.floor(Math.random() * (max - min)) + min;
	g_gs=Math.floor(Math.random() * (max - min)) + min;
	b_gs=Math.floor(Math.random() * (max - min)) + min;
	var str = "RGB("+r_gs+","+g_gs+","+b_gs+")";
	document.getElementById('to_guess').innerHTML=str;

	// rset the info
	var gs="Guess";
	document.getElementById("info").innerHTML=gs;

	//reset the colors 
	for(var i=1;i<=6;i++){
		
		var r=Math.floor(Math.random() * (max - min));
		var g=Math.floor(Math.random() * (max - min));
		var b=Math.floor(Math.random() * (max - min));
		
		var btn_id="col"+i;
		var col="rgb("+r+','+g+','+b+')';

		document.getElementById(btn_id)
		.style.backgroundColor=col; 
	}
	// set a random color butto to to guess value
	num=Math.floor(Math.random() * (6))+1; 
	var rndm_id = "col"+num;
	var col="rgb("+r_gs+","+g_gs+","+b_gs+")";
	document.getElementById(rndm_id)
	.style.backgroundColor=col;
	console.log(num);	
}
function pick(id){
	// if the color buttons are not pressable then return
	if(!active_btn) return;
	
	// increment the chance person took to guess the color
	chances++;
	
	//calculating the color picked 
	var pick = id[id.length-1];

	// if the color picked is right
	if(pick==num){
		document.getElementById("info").innerHTML="Correct";	
		
		// correct the score
		score = (score*(turn-1)+chances)/turn;
		document.getElementById("score").innerHTML=score.toPrecision(2);
		// make the color buttons unpressable
		active_btn = false;
		animation();
	}
	// if the color picked is wrong
	else{
		document.getElementById("info").innerHTML="Try Again!";
	}
}
function animation(){
	var col="rgb("+r_gs+","+g_gs+","+b_gs+")";

	// make the heading background of chosen color
	document.getElementById("to_guess")
	.style.backgroundColor=col;
	
	for(var i=1;i<=6;i++){
		var btn_id="col"+i;
		// make each pallet of chosen color
		document.getElementById(btn_id)
		.style.backgroundColor=col; 
	}
}
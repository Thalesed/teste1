let btn = document.getElementById("btn");
let prvt = document.getElementById("priviet");
let pode = true;
let num = 0;

function but(){
	btn.blur();
	pode = ! pode;
}

function clock(){
	var now = new Date();
	if(pode)
		document.getElementById("hora").textContent = add0(now.getHours()) + ":" + add0(now.getMinutes()) + ":" + add0(now.getSeconds());
}

function add0(tempo){
	if(tempo < 10)
		return ("0" + tempo);
	return tempo;
}

prvt.addEventListener("click", function() {
	let css = document.getElementById("css-link");
	prvt.blur();
	if(num == 0){
		css.href = "baroque.css";
		num = 1;
	}else{
		css.href = "style.css";
		num = 0;
	}
});

btn.addEventListener("click", function() {
	but();
});

setInterval(clock, 1000);

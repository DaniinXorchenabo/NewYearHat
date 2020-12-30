const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head> 
<style type="text/css">
@charset "utf-8";
body {
    background-color: hsla(237,100%,63%,0.94);
    text-align: left;
    float: left;
    background-image: url("https://thumb.cloud.mail.ru/weblink/thumb/xw1/AJBH/BxAFLUxib/фон%20сайта2.jpg?x-email=rkbcu%40mail.ru");
}
 .qw {
    width: 327px;
    height: 117px;
    font-size: 35pt;
    text-align: center;
    background-color: rgba(18,94,0,0.81);
    -webkit-box-shadow: 0 0px;
    box-shadow: 0 0px;
    border: 19px groove rgba(153,66,0,1.00);
    border-radius: 45px;
}
.qr {
	width: 595px;
	height: 83px;
	/* [disabled]margin-top: 12px; */
	text-align: center;
	background-color: rgba(171,247,0,0.66);
	border-color: rgba(151,0,102,0.83);
	position: relative;
}
.qe {
    background-image: -webkit-linear-gradient(270deg,rgba(255,255,255,1.00) 0%,rgba(251,238,71,1.00) 1.04%,rgba(252,172,82,1.00) 46.12%,rgba(253,50,50,1.00) 100%);
    border: 19px groove rgba(137,255,0,1.00);
}
#a5  {

}
.de {
	width: 32px;
	background-color: rgba(255,0,4,1.00);
	height: 383px;
	border-collapse: separate;
	border: 0px double rgba(255,90,90,1.00);
	-webkit-box-shadow: 0 0px 744px 243px rgba(255,0,4,1.00);
	box-shadow: 0 0px 744px 243px rgba(255,0,4,1.00);
	border-radius: 126px;
	visibility: inherit;
	z-index: 9;
	position: relative;
	opacity: 1;
}
.de1 {
	opacity: 1;
	-webkit-animation: de1 2s linear infinite;
	animation: de1 2s linear infinite;
	font-weight: bold;
	color: rgba(255,246,17,1.00);
}
#d2 {
	margin-right: 38px;
}
#d1 {
	margin-right: 0px;
	margin-left: 40px;	/*visibility: hidden;*/
}
.d2 {position: relative;
}
.f1 {

}
#f2  {
    text-align: left;   
}
#f3 {
    text-align: right;
}
.f4{
		
}
	
.osn {
	text-align: center;
	width: 930px;
	height: 1525px;
}

#de3 {
	font-size: 123pt;
	/*position: relative;*/
	z-index: 88;
}
#d4 {
}
#sa1 {
	font-size: 54pt;
	position: relative;
	color: hsla(0,0%,0%,1.00);
	text-align: center;
}
#d4{

}
	
@-webkit-keyframes de1 { 
	0% { color: rgba(255,246,17,1.00); }
	50% { color: hsla(0,0%,0%,0.00); }
	100% { color:rgba(255,246,17,1.00); }
}

@keyframes de1 {  
	0% { color: rgba(255,246,17,1.00); }
	50% { color: hsla(0,0%,0%,0.00); }
	100% { color:rgba(255,246,17,1.00); } 
}
#de4 {
	font-size: 92pt;
}
.de2 {
	opacity: 1;
}
#de5 {
	font-size: 68pt;
}
</style>

<meta charset="utf-8">
</head>
<body>


<div class="osn">
   <p id="sa1">Моя домашняя теплица</p>
	<div>
	<div style="white-space: nowrap;">
		<!--<div style="display: inline-block;"></div>
		<div class="de" id="d2"style="display: inline-block;"><span id="LEDState">4</span><br></div>!-->
<div class="de2 de de1" id="d2" style="display: inline-block;">  </div>	
		
<div class="d2" style="display: inline-block;">  <center>
<h4 class ="qw qr" id="a5" >Температура: <span id="ADCValue">0</span>°C</h4>
<h4 class ="qw qr" id="a6" >Влажность: <span id="ADC1Value">0</span>%</h4>
<h4 class ="qw qr" id="a7">Освещенность: <span id="ADC2Value">0</span></h4></center></div> 
		
<div class="de2 de1 de " id="d1" style="display: inline-block;"></div>
	</div></div>
	
<div class="de2 de1"  id="de3">Опастность!</div>		
<div class="f1">
<div class="f4" style="white-space: nowrap;">
<div id="f2" style="display: inline-block;"><div><button type="button" onclick="sendData(1)" class="qw" id="a1">LED OFF</button>
<button type="button" onclick="sendData(0)" style="display:none" id="a3" class="qe qw">LED ON</button></div> 
<div><button type="button" onclick="sendData4(1)" class="qw" id="b1">полить</button><br></div></div>
	
<div id="f3" style="display: inline-block;"> <div><button type="button" onclick="sendData2(1)" id="a2" class="qw">LED OFF1</button>
<button type="button" onclick="sendData2(0)" style="display:none" id="a4" class="qe qw" >LED ON1</button></div>
	<div><button type="button" onclick="sendData3(1)" id="b2" class="qw">reset</button></div>
	</div>
	</div>
  </div><div><span id="ADC3Value">0</span></div>
  <div class="de1"  id="de4">Риск гниения</div>
 <div class="de1"  id="de5">Закончился раствор</div>	
<!--<div><br>	high humidity : <span id="LEDState1">NA</span></div>!-->
</div>
<script>
	
function sendData(led) {
if (led == 0){
    document.getElementById("a1").style.display = '';
    document.getElementById("a3").style.display = 'none';
	}
else{
    document.getElementById("a3").style.display = '';
    document.getElementById("a1").style.display = 'none';
	}
var xhttp = new XMLHttpRequest();
xhttp.onreadystatechange = function() {
if (this.readyState == 4 && this.status == 200) {
   document.getElementById("LEDState").innerHTML =
   this.responseText;
 }
};
  xhttp.open("GET", "setLED?LEDstate="+led, true);
  xhttp.send();
  return false;
}
function sendData2(led) {
if (led == 0){
    document.getElementById("a2").style.display = '';
    document.getElementById("a4").style.display = 'none';
	}
else{
    document.getElementById("a4").style.display = '';
    document.getElementById("a2").style.display = 'none';
	}
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("LEDState1").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "setLED1?LEDstate1="+led, true);
  xhttp.send();
}

 
function sendData3(led) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("LEDState3").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "setLED3?LEDstate3="+led, true);
  xhttp.send();
  return false;
}

function sendData4(led) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("LEDState4").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "setLED4?LEDstate4="+led, true);
  xhttp.send();
  return false;
}	
setInterval(function() {
  // Call a function repetatively with 2 Second interval
  getData("ADC3");
  getData("ADC");
  getData("ADC1");
  getData("ADC2");
	
}, 4000); //2000mSeconds update rate	
function getData(cc1) {
	
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
        
        var a = this.responseText; 
        document.getElementById(cc1+"Value").innerHTML = a;
		alert(a);
	if (cc1=="ADC3"){
  
		//var a = document.getElementById(cc1+"Value").innerHTML;
		if (((a == "4")||(a == "5"))||(a == "6")){
			document.getElementsByClassName("de2").style.visibility = 'visible';
			if (a == "5"){
				 document.getElementById("de4").style.visibility = 'visible';
			}
			if (a == "6"){
				 document.getElementById("de5").style.visibility = 'visible';
			}
	    }
		if (a == "3"){
			document.getElementsByClassName("de2").style.visibility = 'hidden';
			document.getElementById("de4").style.visibility = 'hidden';
			document.getElementById("de5").style.visibility = 'hidden';
		}
	}
    }
  };
  xhttp.open("GET", "read"+cc1, true);
  xhttp.send();
};

</script>
<br><br>
</body>
</html>
)=====";

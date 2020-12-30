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
    padding-top: 24px;
    background-color: rgba(171,247,0,0.66);
    border-color: rgba(151,0,102,0.83);
}
.qe {
    background-image: -webkit-linear-gradient(270deg,rgba(255,255,255,1.00) 0%,rgba(251,238,71,1.00) 1.04%,rgba(252,172,82,1.00) 46.12%,rgba(253,50,50,1.00) 100%);
    border: 19px groove rgba(137,255,0,1.00);
}
#a5  {

}
.de {
    width: 7vh;
    background-color: rgba(255,0,4,1.00);
    height: 33vh;
    clear: left;
    float: left;
    margin-left: 8vh;
    border-spacing: 2px 1px;
    border-collapse: separate;
    border: 0px double rgba(255,90,90,1.00);
    -webkit-box-shadow: 0 0 334px 132px rgba(255,0,4,1.00);
    box-shadow: 0 0 334px 132px rgba(255,0,4,1.00);
    border-radius: 126px;
    visibility: hidden;
}
.d2 {
}
#d1 {
    clear: none;
    float: right;
    margin-right: 8vh;
    margin-left: 942px;
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
    height: 1294px;
}
#sa1 {
    font-size: 54pt;
}
</style>

<meta charset="utf-8">
</head>
<body>
<div class="osn">
   <h1 id="sa1"> My Teplisa</h1>
		<!--<div class="de"><span id="LEDState">4</span><br></div>
		<div class="de" id="d1"></div>!-->
<div class="d2">  

	<center>
<h4 class ="qw qr" id="a5" >Temperature: <span id="ADC1Value">0</span></h4>
<h4 class ="qw qr" id="a6" >Humidity: <span id="ADC1Value">0</span></h4>
<h4 class ="qw qr" id="a7">Lighting: <span id="ADC2Value">0</span></h4></center>
	</div>  
		
<div class="f1">
<div class="f4" style="white-space: nowrap;">
<div id="f2" style="display: inline-block;"><div><button type="button" onclick="sendData(1)" class="qw" id="a1">LED ON</button>
<button type="button" onclick="sendData(0)" style="display:none" id="a3" class="qe qw">LED OFF1</button></div> 
<div><button type="button" onclick="sendData4(1)" class="qw" id="b1">полить</button><br></div></div>
	
<div id="f3" style="display: inline-block;"> <div><button type="button" onclick="sendData2(1)" id="a2" class="qw">LED ON1</button>
<button type="button" onclick="sendData2(0)" style="display:none" id="a4" class="qe qw" >LED OFF1</button></div>
	<div><button type="button" onclick="sendData3(1)" id="b2" class="qw">reset</button></div>
	</div>
	</div>
	</div>
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
setInterval(function() {
  // Call a function repetatively with 2 Second interval
  getData("ADC");
  getData("ADC1");
	getData("ADC2");
	getData("ADC3");
}, 2000); //2000mSeconds update rate
 
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
	
function getData(cc1) {
	
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById(cc1+"Value").innerHTML =
      this.responseText;
	if (cc1=="ADC3"){
		var a = document.getElementById(cc1+"Value").innerHTML;
		alert(a)
		if (a == "4"){document.getElementById("LEDState").style.visibility = 'visible';}
	}
    }
  }
  xhttp.open("GET", "read"+cc1, true);
  xhttp.send();
}

</script>
<br><br>
</body>
</html>
)=====";


const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head> 
<style type="text/css">
@charset "utf-8";
 .qw {
	background-color: hsla(65,100%,64%,0.87);
	margin-left: 10px;
	margin-right: 10px;
	float: none;
	width: 120px;
	height: 70px;
	margin-top: 10px;
	text-align: center;
	text-shadow: 1px 0px 4px;
	letter-spacing: 2px;
	border: 5px outset hsla(173,100%,62%,0.80);
	background-image: linear-gradient(0deg,rgba(255,255,255,1.00) 0%,rgba(255,178,81,0.91) 0%,rgba(181,255,83,1.00) 58.03%,rgba(180,255,81,1.00) 68.91%,rgba(145,255,0,1.00) 97.93%);
	margin-bottom: 10px;
}
.qe {
	background-image: -webkit-linear-gradient(270deg,rgba(255,255,255,1.00) 0%,rgba(251,238,71,1.00) 1.04%,rgba(252,172,82,1.00) 46.12%,rgba(253,50,50,1.00) 100%);

}
#demo {
	text-align: center;
}
body {
	background-color: hsla(268,94%,75%,0.94);
}
</style>
<meta charset="utf-8">
</head>
<body>
 
<div id="demo">
<h1>The ESP8266 NodeMCU Update web page without refresh 02_3</h1>
	warm : <span id="LEDState">NA</span><br>
	<button type="button" onclick="sendData(1)" class="qw">LED ON</button>
  <button type="button" onclick="sendData(0)"  class="qe qw">LED OFF</button><br>
	high humidity : <span id="LEDState1">NA</span><br>
	<button type="button" onclick="sendData2(1)" class="qw">LED ON1</button>
	<button type="button" onclick="sendData2(0)"  class="qe qw">LED OFF1</button><br>
<div><br>
	Temperature in : <span id="ADCValue">0</span><br>
	Temperature out : <span id="ADC1Value">0</span><br>
	
	
</div>
	
	</div>
 

<script>
function sendData(led) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("LEDState").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "setLED?LEDstate="+led, true);
  xhttp.send();
}
function sendData2(led) {
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
}, 2000); //2000mSeconds update rate
 
function getData(cc1) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById(cc1+"Value").innerHTML =
      this.responseText;
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


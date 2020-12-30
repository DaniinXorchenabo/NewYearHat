const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="icon" href="data:,">
<style>
  
</style>
  </head>
<body>
  <h1>ESP8266 Web Server"+String(ee)+"</h1>
<div id="d3"> dfghjklkjhgfghjhghjhg <span id="ADC3Value">0</span></div>
<script>
  
setInterval(function() {
  getData("ADC3");}, 4000); //2000mSeconds update rate  
  
function getData(cc1) {
    var xhttp = new XMLHttpRequest();
    alert("--- "+cc1+"  "+a);
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
        var a = this.responseText; //ADC3Value
    var elem = document.getElementById('cc1+"Value');
        document.getElementById(cc1+"Value").innerHTML = a;
    elem.style.display = 'none';
  if (cc1 == "ADC3"){
      
    
    if (((a == "4")||(a == "5"))||(a == "6")){
      document.getElementById("ADC3Value").style.display = '';
      elem.style.display = '';
      }
    if ((a == "3")||(a == 3)){
  
      document.getElementById("ADC3Value").style.display = 'none';
      elem.style.display = 'none';
    }
  }
    }
  };
  xhttp.open("GET", "read"+cc1, true);
  xhttp.send();
};</script>
  
</body>
</html>
)=====";


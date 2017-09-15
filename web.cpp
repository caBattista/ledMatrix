#include "arduino.h"
//here are the webpages stored in char arrys because of to long Strings problem
const char _index[] = R"=====(
<html>
<head>
<title>_index</title>
</head>
<body>
<ul>
  <li><a href="/pong">Play Pong</a></li>
  <li><a href="/xmas">Christmas Tree</a></li>
  <li><a href="/ran">Random Color</a></li>
  <li><a href="/view">View</a></li>
  <li><a href="/settings">Settings</a></li>
</ul>

</body>
<style>
ul {
    list-style-type: none;
    margin: 0;
    padding: 0;
    overflow: hidden;
    background-color: #333;
}

li {
    float: left;
    border-right:1px solid #bbb;
}

li a {
    display: block;
    color: white;
    text-align: center;
    padding: 14px 16px;
    text-decoration: none;
    font-family: Arial, serif;
}

li a:hover {
    background-color: #111;
}
</style>
</html>
)=====";

const String _pong = R"=====( 
<html>
<head>
<title>_pong</title>
</head>
<body>

<ul>
  <li><a href="/pong">Play Pong</a></li>
  <li><a href="/xmas">Christmas Tree</a></li>
  <li><a href="/ran">Random Color</a></li>
  <li><a href="/view">View</a></li>
  <li><a href="/settings">Settings</a></li>
</ul>

<font color="white">
<h1 color="white">Play Pong</h1>
<form name="form1" id="form1">
<br><br>
  <p>
  Position <input type="text" name="y">
  Offset <input type="text" name="oy">
  </p>
 
</form>
</font>
<div class="container">
  <div class="toggle">
    <input type="checkbox" onclick ="sendPos()" >
    <span class="button"></span>
    <span class="label">Go</span>
  </div>
  <div class="toggle">
    <input type="checkbox" onclick ="stopInterval()">
    <span class="button"></span>
    <span class="label">Stop</span>
  </div>
    <div class="toggle">
    <input type="checkbox" onclick ="offset()">
    <span class="button"></span>
    <span class="label">Rst</span>
  </div>
</div>
</body>
<style>
ul {
    list-style-type: none;
    margin: 0;
    padding: 0;
    overflow: hidden;
    background-color: #333;
}

li {
    float: left;
    border-right:1px solid #bbb;
}

li a {
    display: block;
    color: white;
    text-align: center;
    padding: 14px 16px;
    text-decoration: none;
    font-family: Arial, serif;
}

li a:hover {
    background-color: #111;
}


html, body {
  font-family: "Lato", sans-serif;
  background: #333;
  text-align: center;
  height: 100%;
}

.container {
  text-align: center;
  position: absolute;
  margin-top: -80px;
  width: 100%;
  top: 50%;
}

.toggle {
  margin: 10px;
  display: inline-block;
}

.toggle {
  box-shadow: inset 0 0 35px 5px rgba(0, 0, 0, 0.25), inset 0 2px 1px 1px rgba(255, 255, 255, 0.9), inset 0 -2px 1px 0 rgba(0, 0, 0, 0.25);
  border-radius: 8px;
  background: #ccd0d4;
  position: relative;
  height: 140px;
  width: 140px;
}
.toggle:before {
  box-shadow: 0 0 17.5px 8.75px #fff;
  border-radius: 118.3px;
  background: #fff;
  position: absolute;
  margin-left: -50.4px;
  margin-top: -50.4px;
  opacity: 0.2;
  content: "";
  height: 100.8px;
  width: 100.8px;
  left: 50%;
  top: 50%;
}
.toggle .button {
  -webkit-filter: blur(1px);
  -moz-filter: blur(1px);
  filter: blur(1px);
  transition: all 300ms cubic-bezier(0.23, 1, 0.32, 1);
  box-shadow: 0 15px 25px -4px rgba(0, 0, 0, 0.5), inset 0 -3px 4px -1px rgba(0, 0, 0, 0.2), 0 -10px 15px -1px rgba(255, 255, 255, 0.6), inset 0 3px 4px -1px rgba(255, 255, 255, 0.2), inset 0 0 5px 1px rgba(255, 255, 255, 0.8), inset 0 20px 30px 0 rgba(255, 255, 255, 0.2);
  border-radius: 96.32px;
  position: absolute;
  background: #ccd0d4;
  margin-left: -48.16px;
  margin-top: -48.16px;
  display: block;
  height: 96.32px;
  width: 96.32px;
  left: 50%;
  top: 50%;
}
.toggle .label {
  transition: color 300ms ease-out;
  text-shadow: 1px 1px 3px #ccd0d4, 0 0 0 rgba(0, 0, 0, 0.8), 1px 1px 4px #fff;
  line-height: 139px;
  text-align: center;
  position: absolute;
  font-weight: 700;
  font-size: 42px;
  display: block;
  opacity: 0.9;
  height: 100%;
  width: 100%;
  color: rgba(0, 0, 0, 0.4);
}

.toggle input {
  opacity: 0;
  position: absolute;
  cursor: pointer;
  z-index: 1;
  height: 100%;
  width: 100%;
  left: 0;
  top: 0;
}

.toggle input:checked ~ .button {
  box-shadow: 0 15px 25px -4px rgba(0, 0, 0, 0.4), inset 0 -8px 25px -1px rgba(255, 255, 255, 0.9), 0 -10px 15px -1px rgba(255, 255, 255, 0.6), inset 0 8px 20px 0 rgba(0, 0, 0, 0.2), inset 0 0 5px 1px rgba(255, 255, 255, 0.6);
}

</style>
<script>
var b = 0;
var timer = 0;
var connection = 0;
var clicked = 0;
window.addEventListener('deviceorientation', function(event) {
    b = (((event.beta+180)*(255/360)).toFixed(0));
    document.form1.y.value = b-document.form1.oy.value+127;
    });
function offset(){
  document.form1.oy.value = b;
  }
function sendPos(){
  if(clicked==0){
    clicked = 1;
    offset();
    connection = new WebSocket('ws://'+location.hostname+':85/', ['arduino']);
        connection.onopen = function () {
        connection.send('pong');
        };
    connection.onerror = function (error) {
        console.log('WebSocket Error ', error);
        };
    connection.onmessage = function (e) {
        console.log('Server: ', e.data);
        };
    timer = setInterval(function() {
        var beta = parseInt(document.form1.y.value).toString(16);
        if(b.length < 2) { 
          beta = '0' + beta;
        }
        connection.send(beta);
        }, 30);     
      }
    }
  function stopInterval(){
    clicked = 0;
    clearInterval(timer);
    connection.onclose = function () {}; // disable onclose handler first
    connection.close()
    }
</script>
</html>
)=====";

const char _view[] = R"=====(
<html>
<head>
<title>_view</title>
</head>
<body>

<ul>
  <li><a href="/pong">Play Pong</a></li>
  <li><a href="/xmas">Christmas Tree</a></li>
  <li><a href="/ran">Random Color</a></li>
  <li><a href="/view">View</a></li>
  <li><a href="/settings">Settings</a></li>
</ul>
<br>
<canvas id="myCanvas" width="1000" height="480" style="border:1px solid #d3d3d3;">
Your browser does not support the HTML5 canvas tag.</canvas>
<br><br>
<form name="form" id="form">
FPS<input type="text" name="frames">
</form>
</body>
<style>
ul {
    list-style-type: none;
    margin: 0;
    padding: 0;
    overflow: hidden;
    background-color: #333;
}

li {
    float: left;
    border-right:1px solid #bbb;
}

li a {
    display: block;
    color: white;
    text-align: center;
    padding: 14px 16px;
    text-decoration: none;
    font-family: Arial, serif;
}

li a:hover {
    background-color: #111;
}
</style>
<script>
var frCount = 0;
var c = document.getElementById("myCanvas");
var ctx = c.getContext("2d");

connection = new WebSocket('ws://'+location.hostname+':85/', ['arduino']);
        connection.onopen = function () {
        connection.send('view');
        };
    connection.onerror = function (error) {
        console.log('WebSocket Error ', error);
        };
    connection.onmessage = function (e) {
        console.log('Server: ', e.data);
        var pixels = e.data;
        var pixel = pixels.split('#');
        var count = 1;
        for(y = 0; y < 12; y++){
          if(y % 2 == 0){
            for(x = 0; x < 25; x++){
              ctx.fillStyle = '#' + pixel[count];
              ctx.fillRect(x*40,y*40,40,40);
              count++;
              }
            }
            else{
              for(x = 24; x > -1; x--){
                ctx.fillStyle = '#' + pixel[count];
                ctx.fillRect(x*40,y*40,40,40);
                count++;
                }
              }
          }
        frCount++;
        };
    timer = setInterval(function() {
      document.form.frames.value = frCount;
      frCount=0;
        }, 1000);
</script>
</html>
)=====";

const char _settings[] = R"=====(
<html>
<head>
<title>_index</title>
</head>
<body>
<ul>
  <li><a href="/pong">Play Pong</a></li>
  <li><a href="/xmas">Christmas Tree</a></li>
  <li><a href="/ran">Random Color</a></li>
  <li><a href="/view">View</a></li>
  <li><a href="/settings">Settings</a></li>
</ul>
<h2>Available Wifi Networks</h2>
<table id="myTable">
<tbody>
  <tr>
    <th>Nr</th>
    <th>SSID</th>
    <th>Signal Strength</th>
    <th>Channel</th>
    <th>BSSID (MAC)</th>
    <th>Encryption</th>
    <th>Hidden</th>
  </tr>
</tbody>
</table>
<h2>Add Router to connect to</h2>
<form name="form" id="form">
  SSID<input type="text" name="ssid">
  Password<input type="text" name="pass">
</form>
<button id="b1"; type="button" onclick ="save()">Save to Esp8266</button>
<br>
<br>
You need to restart the Esp8266 for the changes to take effect.
<h2>Currently connected to</h2>
</body>
<style>
body{
  font-family: Arial, serif;

}
ul {
    list-style-type: none;
    margin: 0;
    padding: 0;
    overflow: hidden;
    background-color: #333;
}

li {
    float: left;
    border-right:1px solid #bbb;
}

li a {
    display: block;
    color: white;
    text-align: center;
    padding: 14px 16px;
    text-decoration: none;
}

li a:hover {
    background-color: #111;
}

table, th, td {
  border: 1px solid black;
  border-collapse: collapse;
}
th, td {
  padding: 5px;
  text-align: left;    
}
</style>
<script>
var i = 0;
connection = new WebSocket('ws://'+location.hostname+':85/', ['arduino']);
        connection.onopen = function () {
        connection.send('set');
        };
    connection.onerror = function (error) {
        console.log('WebSocket Error ', error);
        };
    connection.onmessage = function (e) {
        console.log( e.data);
        if(e.data=='*'){
        i = 1;
        console.log(i);
          }
        if(i==0){  
          var cell = e.data.split('#');
          addRow(cell[0],cell[1],cell[2],cell[3],cell[4],cell[5],cell[6])
        }
        if(i==1 && e.data!='*'){  
          var str = e.data.split('#');
          addPara("SSID: " + str[0]);
          addPara("Soft AP IP: " + str[1]);
          addPara("Local IP: " + str[2]);
          addPara("Gateway IP: " +  str[3]);
          addPara("Subnet Mask: " + str[4]);
        }
        };

function addPara(a) {
    var para = document.createElement("P");
    var t = document.createTextNode(a);
    para.appendChild(t);
    document.body.appendChild(para);
}

function addRow(a,b,c,d,e,f,g)
{
  if (!document.getElementsByTagName) return;
  tabBody = document.getElementsByTagName("tbody").item(0);
  row = document.createElement("tr");
  cell1 = document.createElement("td");
  cell2 = document.createElement("td");
  cell3 = document.createElement("td");
  cell4 = document.createElement("td");
  cell5 = document.createElement("td");
  cell6 = document.createElement("td");
  cell7 = document.createElement("td");
  textnode1 = document.createTextNode(a);
  textnode2 = document.createTextNode(b);
  textnode3 = document.createTextNode(c);
  textnode4 = document.createTextNode(d);
  textnode5 = document.createTextNode(e);
  textnode6 = document.createTextNode(f);
  textnode7 = document.createTextNode(g);
  cell1.appendChild(textnode1);
  cell2.appendChild(textnode2);
  cell3.appendChild(textnode3);
  cell4.appendChild(textnode4);
  cell5.appendChild(textnode5);
  cell6.appendChild(textnode6);
  cell7.appendChild(textnode7);
  row.appendChild(cell1);
  row.appendChild(cell2);
  row.appendChild(cell3);
  row.appendChild(cell4);
  row.appendChild(cell5);
  row.appendChild(cell6);
  row.appendChild(cell7);
  tabBody.appendChild(row);
  }
function save()
{
  var data = "#" + document.form.ssid.value + "#" + document.form.pass.value;
  connection.send(data);
  }
</script>
</html>
)=====";

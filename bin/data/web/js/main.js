var socket;

var messageDiv;
var statusDiv;
var button;
var textField;

$(document).ready( function() {
	setupSocket();
});


// setup web socket
function setupSocket(){

	// setup websocket
	// get_appropriate_ws_url is a nifty function by the libwebsockets people
	// it decides what the websocket url is based on the broswer url
	// e.g. https://mygreathost:9099 = wss://mygreathost:9099

	if (BrowserDetect.browser == "Firefox") {
		socket = new MozWebSocket(get_appropriate_ws_url());
	} else {
		socket = new WebSocket(get_appropriate_ws_url());
	}
	
	// open
	try {
		socket.onopen = function() {
			
		} 

		// received message
		socket.onmessage =function got_packet(msg) {
		  console.log(msg);
		  if(msg.data == "true"){
  		  $('#beer-pic').addClass('active');
		  }
		  else
		  {
  		  $('#beer-pic').removeClass('active');
		  }
		}

		socket.onclose = function(){
			
		}
	} catch(exception) {
		//alert('<p>Error' + exception);  
		console.log(exception);
	}
}
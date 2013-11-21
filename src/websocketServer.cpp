#include "websocketServer.h"

//--------------------------------------------------------------
websocketServer::websocketServer(){
    setup();
}

void websocketServer::setup(){
    // setup a server with default options on port 9092
    // - pass in true after port to set up with SSL
    //bConnected = server.setup( 9093 );
    
    ofxLibwebsockets::ServerOptions options = ofxLibwebsockets::defaultServerOptions();
    options.port = 4000;
	options.bUseSSL = false; //ssl not working on Win right now!
    bConnected = server.setup( options );
    
	cout << "CONNECTED? "<<bConnected<<endl;
    
    // this adds your app as a listener for the server
    server.addListener(this);
    
    //ofBackground(0);
    //ofSetFrameRate(60);
}

void websocketServer::update(){}

void websocketServer::draw(){}

void websocketServer::setKegIsPouring(bool isPouring){
    if( kegIsPouring != isPouring ){
        kegIsPouring = isPouring;
        if(isPouring){
            server.send("true");
        }
        else
        {
            server.send("false");
        }
        
    }
}

//--------------------------------------------------------------
void websocketServer::onConnect( ofxLibwebsockets::Event& args ){
    cout<<"on connected"<<endl;
}

//--------------------------------------------------------------
void websocketServer::onOpen( ofxLibwebsockets::Event& args ){
    cout<<"new connection open"<<endl;
    messages.push_back("New connection from " + args.conn.getClientIP() + ", " + args.conn.getClientName() );
}

//--------------------------------------------------------------
void websocketServer::onClose( ofxLibwebsockets::Event& args ){
    cout<<"on close"<<endl;
    messages.push_back("Connection closed");
}

//--------------------------------------------------------------
void websocketServer::onIdle( ofxLibwebsockets::Event& args ){
    cout<<"on idle"<<endl;
}

//--------------------------------------------------------------
void websocketServer::onMessage( ofxLibwebsockets::Event& args ){
    cout<<"got message "<<args.message<<endl;
    
    // trace out string messages or JSON messages!
    if ( !args.json.isNull() ){
        messages.push_back("New message: " + args.json.toStyledString() + " from " + args.conn.getClientName() );
    } else {
        messages.push_back("New message: " + args.message + " from " + args.conn.getClientName() );
    }
    
    // echo server = send message right back!
    args.conn.send( args.message );
}

//--------------------------------------------------------------
void websocketServer::onBroadcast( ofxLibwebsockets::Event& args ){
    cout<<"got broadcast "<<args.message<<endl;
}

void websocketServer::sendData( string data ){
    server.send( toSend );
}

//--------------------------------------------------------------
void websocketServer::keyPressed(int key){
//    // do some typing!
//    if ( key != OF_KEY_RETURN ){
//        if ( key == OF_KEY_BACKSPACE ){
//            if ( toSend.length() > 0 ){
//                toSend.erase(toSend.end()-1);
//            }
//        } else {
//            toSend += key;
//        }
//    } else {
//        // send to all clients
//        server.send( toSend );
//        messages.push_back("Sent: '" + toSend + "' to "+ ofToString(server.getConnections().size())+" websockets" );
//        toSend = "";
//    }
}

//--------------------------------------------------------------
void websocketServer::keyReleased(int key){
    
}

//--------------------------------------------------------------
void websocketServer::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void websocketServer::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void websocketServer::mousePressed(int x, int y, int button){
//    string url = "http";
//    if ( server.usingSSL() ){
//        url += "s";
//    }
//    url += "://localhost:" + ofToString( server.getPort() );
//    ofLaunchBrowser(url);
}

//--------------------------------------------------------------
void websocketServer::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void websocketServer::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void websocketServer::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void websocketServer::dragEvent(ofDragInfo dragInfo){
    
}
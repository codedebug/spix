# Spix
Spix is a minimally invasive UI testing library that enables your
Qt/Qml app's UI to be controlled either via c++ code, or through a http RPC
interface.

UI elements are referenced through names and paths which are robust against
design changes. To click on a button you write
```
mouseClick("mainWindow/ok_button");
```

To provide an RPC test interface to your App,
only add these three lines to your `main(...)` function:
```
spix::AnyRpcServer server;
auto bot = new spix::QtQmlBot();
bot->runTestServer(server);
```

And a test script in python could look like this:
```
import xmlrpc.client

s = xmlrpc.client.ServerProxy('http://localhost:9000')
s.mouseClick("mainWindow/Button_1")
s.wait(200)
s.mouseClick("mainWindow/Button_2")
resultText = s.getStringProperty("mainWindow/results", "text")
s.quit()
```

# Requirements
* Qt
* AnyRPC

# Current Features
* Send mouse events (click, move, drag/drop)
* Drop mime data from external apps
* Enter text
* Check existence and visibility of items
* Get property values of items (text, position, color, ...)
* Take and save a screenshot
* Quit the app
* Remote control, also of embedded devices / ios
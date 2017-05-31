var screenshots = require('./build/Release/screenshots');

function runAsync() {
	screenshots.screenShotsAsync("E:\\aaaq555中文qqq.png", (a, b)=>{
		console.log("a:" + a+".b:"+b);
	});
}

runAsync();

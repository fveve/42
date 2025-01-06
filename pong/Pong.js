/*------------Canvas and background setup---------*/
let end_w = 500;
let end_h = 500;

const	canvas = document.querySelector("canvas");
canvas.width = end_w;
canvas.height = end_h;
const	ctx = canvas.getContext("2d");

let width = 25;
let height = 100;
let maxBounceAngle = 50;
let speed = 10;

function getRandomArbitrary(min, max) {
	return Math.random() * (max - min) + min;
  }
  
/*----------------------------------------------*/
class Ball {
	constructor(x, y, radius)
	{
		this.x = x;
		this.y = y;
		this.radius = radius;
		this.diameter = radius * 2;
		this.dx = 1;
		this.dy = 1;
	}
	isPlayerHit(p)
	{
		if (this.x + this.radius> p.x && this.x - this.radius < p.x + width && 
			this.y + this.radius > p.y && this.y  + this.radius < p.y + height)
			return (true);
		return (false);
	}
	drawBall ()
	{
		ctx.beginPath();
		ctx.fillStyle = "white";
		ctx.arc(this.x, this.y, this.radius, 0, Math.PI * 2);
		ctx.fill();
		ctx.closePath();
	}
	calculate_bounceAngle(paddle)
	{
		let intersectionY = this.y + this.diameter; // Point of intersection between the paddle and the ball
		let relativeIntersectY = (paddle.y + (height/2)) - intersectionY;//aproximation of where the ball hit the paddle so that the ball does not have a predictable pattern
		let normalizedRelativeIntersectionY = relativeIntersectY/(height / 2);//normalize the relative intersection so that its independent of the scaling of the paddle
		let bounceAngle = normalizedRelativeIntersectionY * maxBounceAngle;
		
		return bounceAngle;
	}
	moveBall(p1, p2)
	{
		ctx.beginPath();
		ctx.fillStyle = "black";
		ctx.arc(this.x, this.y, this.radius + 1, 0, Math.PI * 2);
		ctx.fill();
		ctx.closePath();
		if (this.isPlayerHit(p1))
		{
			this.dx = speed * Math.cos(this.calculate_bounceAngle(p1));			
			if (this.dx < 0)
				this.dx *= -1;
			this.dy = speed * Math.sin(this.calculate_bounceAngle(p1));
		}
		if (this.isPlayerHit(p2))
		{
			this.dx = speed * Math.cos(this.calculate_bounceAngle(p2));
			if (this.dx > 0)
				this.dx *= -1;
			this.dy = speed * Math.sin(this.calculate_bounceAngle(p2));

		}
		if (this.y <= 0)
		{
			this.dy = -this.dy;
		}
		if (this.y >= 500)
		{
			this.dy = -this.dy; // Reverse vertical direction
		}
		if (this.x <= 0 || this.x >= end_w) {
			this.x = 250; // Reset ball to center
			this.y = 250;
			this.dx = 1; // Reset speed
			this.dy = 0;
			trigger = 0;
		}
		this.x += this.dx;
		this.y += this.dy;
		this.drawBall();
	}

}

class	Player{
	constructor (x,y)
	{
		this.x = x;
		this.y = y;
		this.points = 0;
	}
	movePlayer(y)
	{
		this.y += y;
	}
	drawPlayer()
	{
		ctx.fillStyle = "white"
		ctx.fillRect(this.x, this.y, width, height);
	}
}

let p1 = new Player(10, 250);
let p2 = new Player(465, 250);

let	ball = new Ball(250, 250, 10);

let trigger = 0;

// Track key states
const keys = {};

// Update key state on keydown
document.addEventListener('keydown', (event) => {
	keys[event.key] = true;
});

// Update key state on keyup
document.addEventListener('keyup', (event) => {
	keys[event.key] = false;
});

function movement()
{
	if ((keys["z"] || keys["w"]) && p1.y > 0) {
		p1.movePlayer(-(speed + 2));
	}
	if (keys["s"] && p1.y < end_h - 100) {
		p1.movePlayer(speed + 2);
	}
	if (keys["ArrowUp"] && p2.y > 0) {
		p2.movePlayer(-(speed + 2));
	}
	if (keys["ArrowDown"] && p2.y < end_h - 100) {
		p2.movePlayer(speed + 2);
	}
	if (keys[" "])
		trigger = 1;
	//console.log(trigger);
	//console.log(keys);
}

function drawFrame()
{
	ctx.clearRect(0, 0, canvas.width, canvas.height);
	ctx.fillStyle = "black"
	ctx.fillRect(0, 0, canvas.width, canvas.height);
	movement();
	if (trigger == 1)
		ball.moveBall(p1, p2);
	p1.drawPlayer();
	p2.drawPlayer();
	if (ball.x <= 0)
		p2.points++;
	if (ball.x >= 500)
		p1.points+= 1;
	document.getElementById("p1 points").innerText = p1.points;
	document.getElementById("p2 points").innerText = p2.points;
	//console.log(p1.points);
	requestAnimationFrame(drawFrame);
}


p1.drawPlayer();
p2.drawPlayer();
ball.drawBall();

drawFrame();

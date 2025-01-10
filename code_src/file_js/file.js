


duck = function( name = 'default ' )
{
   this.type = "duck";
   this.name = name;


}

var d = new duck("donal");
duck.prototype.leg = 2   ;



console.log(d.leg );






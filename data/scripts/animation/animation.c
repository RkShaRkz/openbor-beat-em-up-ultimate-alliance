// SLAM - THROW //////////////////////////////////////////////////////////////////////////////

void slamstart()
{//Slam Starter for grab slams
//Use finish or throw after using this
	void self 	= getlocalvar("self");
	void target = getlocalvar("Target" + self);

	if(target==NULL())
	{
		target = getentityproperty(self, "grabbing");
		setlocalvar("Target" + self, target);
	}
	
	if(target!=NULL())
	{
		damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL7")); // Slam Starter
	}
}

void slamstart2()
{//Slam Starter for nongrab slams
//Use finish or throw after using this
	void self 	= getlocalvar("self");
	void target = getlocalvar("Target" + self);

	if(target==NULL())
	{
		target = getentityproperty(self, "opponent");
		setlocalvar("Target" + self, target);
	}
	
	if(target!=NULL())
	{
		damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL7")); // Slam Starter
	}
}

void position(int Frame, float dx, float dy, float dz, int face)
{//Modify grabbed entity's position relative to grabber
//Use slamstart 1st before using this
	void self 		= getlocalvar("self");
	void target 	= getlocalvar("Target" + self);
	void THealth 	= getentityproperty(target,"health"); //Get opponents's health

	if(target==NULL())
	{
		target = getentityproperty(self, "grabbing");
		setlocalvar("Target" + self, target);
	}
	
	if(target!=NULL())
	{
		if(THealth <= 0)
		{
			depost(0);
			finish(0,0,-1,0,0,0);
			slammed2(0);
		} else {
			updateframe(target, Frame);
			bindentity(target, self, dx, dz, dy, face, 0);
		}
	}
}

void depost(int Gr)
{//Release grabbed entity
	void self 	= getlocalvar("self");
	void target = getlocalvar("Target" + self);

	if(target==NULL())
	{
		target = getentityproperty(self, "grabbing");
		setlocalvar("Target" + self, target);
	}
	
	if(target!=NULL())
	{
		bindentity(target, NULL());

		if(Gr == 1)
		{
			int x = getentityproperty(target, "x");
			int z = getentityproperty(target, "z");
			changeentityproperty(target, "position", x, z, 0);
		}
	}
}

void finish(int Damage, int Type, int x, int y, int z, int Face)
{//Damage as slam or throw finisher
	void self 	= getlocalvar("self");
	void target = getlocalvar("Target" + self);
	int SDir 	= getentityproperty(target,"direction");
	int MDir;

	if(Face==0){ // Same facing?
		MDir = SDir;
	}

	if(Face==1){ // Opposite facing?

		if(SDir==0){ // Facing left?
			MDir = 1;
		} else { MDir = 0;}
	}

	if(target==NULL())
	{
		target = getentityproperty(self, "grabbing");
		setlocalvar("Target" + self, target);
	}
	
	if(target!=NULL())
	{
		int dir = getentityproperty(target,"direction"); //Get opponent's facing direction
		if(dir==0){ // Facing left?
			x = -x;
		}

		if(Type==1)
		{
			damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL")); // 1st Finisher
		}

		if(Type==2)
		{
			damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL9")); // 2nd Finisher
		}

		if(Type==3)
		{
			damageentity(target, self, Damage, 1, openborconstant("ATK_NORMAL8")); // 3rd Finisher
		}

		tossentity(target, y, x, z); //Toss opponent ;)
		changeentityproperty(target, "direction", MDir);
	}
}

void throw(int Damage, int Type, int Vx, int Vy, int Vz, int Face)
{//Damage as throw finisher
	void self 	= getlocalvar("self");
	void atk 	= getlocalvar("attacker");
	void target = getlocalvar("Target" + self);
	int Offense = getentityproperty(self,"offense");
	int z 		= getentityproperty(self,"z");
	int SDir 	= getentityproperty(target,"direction");
	int MDir;

	if(Face==0){ // Same facing?
		MDir = SDir;
	}

	if(Face==1){ // Opposite facing?

		if(SDir==0){ // Facing left?
			MDir = 1;
		} else { MDir = 0;}
	}

	if(target==NULL())
	{
		target = getentityproperty(self, "grabbing");
		setlocalvar("Target" + self, target);
	}
	
	if(target!=NULL())
	{
		int dir = getentityproperty(target,"direction"); //Get opponent's facing direction
		if(dir==0){ // Facing left?
			Vx = -Vx;
		}

		if(Type==1)
		{
			damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL")); // 1st throw type
		}

		if(Type==2)
		{
			damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL9")); // 2nd throw type
		}

		if(Type==3)
		{
			damageentity(target, self, 0, 1, openborconstant("ATK_NORMAL8")); // 3rd throw type
		}

			changeentityproperty(target, "attacking", 1);
			changeentityproperty(target, "damage_on_landing", Damage*Offense);
			changeentityproperty(target, "projectile", 1);
			changeentityproperty(target, "direction", MDir);

		if(z > (openborconstant("PLAYER_MIN_Z") + openborconstant("PLAYER_MAX_Z")) / 2 ) {
			Vz = -Vz ;
		}

			tossentity(target, Vy, Vx, Vz); // Toss opponent ;
	}
}

void grabend()
{//End grab jump and free enemy on the ground if no attack is performed (MAX)
	void self 	= getlocalvar("self");
	void target = getlocalvar("Target" + self);

	if(target==NULL())
	{
		target = getentityproperty(self, "grabbing");
		setlocalvar("Target" + self, target);
	}
	
	if(target!=NULL())
	{
		changeentityproperty(target,"damage_on_landing",0);
		changeentityproperty(target,"nograb",0);
		changeentityproperty(target,"aiflag","falling",0);
		changeentityproperty(target,"aiflag","drop",0);
		changeentityproperty(target,"aiflag","projectile",0);
		changeentityproperty(target,"takeaction", "common_attack_proc");
		executeanimation(target, openborconstant("ANI_IDLE"));
		setidle(target);
		depost(0);
	}
}

void antiwall(int Dist, int Move, int Distz)
{// Checks if there is wall at defined distance
// If there is wall, entity will be moved away with defined movement
	void self 		= getlocalvar("self");
	int Direction 	= getentityproperty(self, "direction");
	int x 			= getentityproperty(self, "x");
	int z 			= getentityproperty(self, "z");
	int subwall		= getentityproperty(self, "subject_to_wall");
	float H;
	float Hz;

	if(Direction == 0){ //Is entity facing left?                  
		Dist = -Dist; //Reverse Dist to match facing
		Move = -Move; //Reverse Move to match facing
	}

	H 	= checkwall(x+Dist,z);
	Hz 	= checkwall(x+Dist,z+Distz);

	if(Hz > 0){
		if(subwall == 1)
		{
			changeentityproperty(self, "position", x, z-Distz);
		}
	}

	if(H > 0){
		if(subwall == 1)
		{
			changeentityproperty(self, "position", x+Move);
		}
	}
}

void antiwallG(int Dist, int Move, int Distz)
{// Checks if there is wall at defined distance
// If there is wall, entity (Self/Grabbed) will be moved away with defined movement
	void self 		= getlocalvar("self");
	void target		= getentityproperty(self, "grabbing");
	int Direction 	= getentityproperty(self, "direction");
	int x 			= getentityproperty(self, "x");
	int Tx 			= getentityproperty(target, "x");
	int z 			= getentityproperty(self, "z");
	int Tz 			= getentityproperty(target, "z");
	int subwall		= getentityproperty(self, "subject_to_wall");
	float H;
	float Hz;

	if(Direction == 0){ //Is entity facing left?                  
		Dist = -Dist; //Reverse Dist to match facing
		Move = -Move; //Reverse Move to match facing
	}

	H 	= checkwall(x+Dist,z);
	Hz 	= checkwall(x+Dist,z+Distz);

	if(Hz > 0){
		if(subwall == 1)
		{
			changeentityproperty(self, "position", x, z-Distz);
			changeentityproperty(target, "position", Tx, Tz-Distz);
		}
	}

	if(H > 0){
		if(subwall == 1)
		{
			changeentityproperty(self, "position", x+Move);
			changeentityproperty(target, "position", Tx+Move);
		}
	}
}

void antioffG(float dx)
{// Checks if enemy is offscreen at defined distance
// If enemy is offscreen, entity (Self/Grabbed) will be moved away with defined movement
	void self 		= getlocalvar("self");
	void target		= getentityproperty(self, "grabbing");
	int x 			= getentityproperty(self, "x");
	int Tx 			= getentityproperty(target, "x");
	int XPos 		= openborvariant("xpos"); //Get screen edge's position

    if(Tx > XPos + 480 + dx)// Offscreen to the right?
	{
		changeentityproperty(self, "position", x+20);
		changeentityproperty(target, "position", Tx-20);
    }else if(Tx < XPos - dx) // Offscreen to the left?
	{
		changeentityproperty(self, "position", x-20);
		changeentityproperty(target, "position", Tx+20);
    }
}

// MOVES //////////////////////////////////////////////////////////////////////////////

void moveX(int V)
{//Moves with random angle (NINJA)
//V : Base velocity
    int r = rand()%180;
    int Vx;
    int Vz;

    Vx = V*cos(r);
    Vz = V*sin(r);

    dasher(Vx,0,Vz);
}

void dash()
{// Dash with previously attained speed!
    void self = getlocalvar("self");
    float Vx = getlocalvar("x"+self);
    float Vz = getlocalvar("z"+self);
    if( Vx!=NULL() && Vz!=NULL() ){
      changeentityproperty(self, "velocity", Vx, Vz); //Move towards target!
    }
}

void dasher( float Vx, float Vy, float Vz )
{// Dash with desired speed!
    void self 	= getlocalvar("self");
    int dir 	= getentityproperty(self,"direction");

    if(dir==0){ // Facing left?
      Vx = -Vx ;
    }

    changeentityproperty(self, "velocity", Vx, Vz, Vy); //Move!
}

void leap(float Vely)
{// Leap with previously attained speed!
    void self 	= getlocalvar("self");
    float Vx 	= getlocalvar("x"+self);
    float Vz 	= getlocalvar("z"+self);
	
    if( Vx!=NULL() && Vz!=NULL()){
      tossentity(self, Vely, Vx, Vz); //Leap towards target!
    }
}

void leaper(float Vx, float Vy, float Vz )
{// Leap with desired speed!
    void self 	= getlocalvar("self");
    int dir 	= getentityproperty(self,"direction");

    if(dir==0){ // Facing left?
      Vx = -Vx ;
    }

    tossentity(self, Vy, Vx, Vz); //Leap!
}

void leaperX(float Vx, float Vy, float Vz)
{// Leap with desired speed and random X/Z axis (SHIVA DODGE)
    void self 	= getlocalvar("self");
    int dir 	= getentityproperty(self,"direction");
	int iR1		= rand()%4;
	int iR2		= rand()%4;

	if(iR1 >= 0 && iR1 <= 2){
		Vx = -Vx;
    }
	
	if(iR2 >= 0 && iR2 <= 2){
		Vz = -Vz;
    }
	
    tossentity(self, Vy, Vx, Vz); //Leap!
}

void stop()
{// Stop hero's movement!
    void self = getlocalvar("self");
	
    changeentityproperty(self, "velocity", 0, 0, 0); //Stop moving!
}

void stop2()
{// Stop projectile's movement!
	void self = getlocalvar("self");

	changeentityproperty(self, "velocity", 0, 0, 0); //Stop moving!
	changeentityproperty(self, "speed", 0, 0, 0); //Stop moving!
}

void target(float Velx, float Velz, float dx, float dz, int Stop)
{// Targetting opponent before leaping or dashing.
// Velx = x Velocity
// Velz = z Velocity
// dx = x added distance
// dz = z added distance
// Stop = flag to stop moving if no target is found

	void self 	= getlocalvar("self");
	int dir 	= getentityproperty(self, "direction");
	float x 	= getentityproperty(self, "x");
	float z 	= getentityproperty(self, "z");

	if(dir == 0){ //Is entity facing left?                  
		dx = -dx; //Reverse X direction to match facing
	}

	setlocalvar("T"+self, findtarget(self)); //Get nearest player

	if(getlocalvar("T"+self) != NULL()){
		void target = getlocalvar("T"+self);
		float Tx = getentityproperty(target, "x");
		float Tz = getentityproperty(target, "z");

		if(Tx < x){
			changeentityproperty(self, "direction", 0);
		} else {
			changeentityproperty(self, "direction", 1);
		}

		x = x+dx;
		z = z+dz;
		float Disx = Tx - x;
		float Disz = Tz - z;

	//Set both distance as positive value
		if(Disx < 0){
			Disx = -Disx;
		}

		if(Disz < 0){
			Disz = -Disz;
		}

	// Calculate velocity for targetting
		if(Disz < Disx){
			if(Tx < x){
				setlocalvar("x"+self, -Velx);
			} else { setlocalvar("x"+self, Velx); }

			setlocalvar("z"+self, Velx*(Tz-z)/Disx);
		} else {
			if(Tz < z){
				setlocalvar("z"+self, -Velz);
			} else { setlocalvar("z"+self, Velz); }

			setlocalvar("x"+self, Velz*(Tx-x)/Disz);
		}

	} else {
		if(Stop == 1){
			setlocalvar("z"+self, 0);
			setlocalvar("x"+self, 0);
		} else { setlocalvar("z"+self, 0);
			if(dir==0){
				setlocalvar("x"+self, -Velx);
			} else { setlocalvar("x"+self, Velx); }
		}
	}
}

void clearL()
{// Clears all local variables
    clearlocalvar();
}

void clearE(int Num)
{ // Clears entity variable
    void self = getlocalvar("self");
	
    setentityvar(self, Num, NULL());
}

// KEYS //////////////////////////////////////////////////////////////////////////////

void keymove(float V)
{// Move hero if direction button is pressed
	void self 	= getlocalvar("self");
	int iPIndex = getentityproperty(self,"playerindex"); //Get player index
	float xdir 	= 0;
	float zdir 	= 0;

    if(playerkeys(iPIndex, 0, "moveleft")){// Left is pressed?
		xdir = -V;
	}else if(playerkeys(iPIndex, 0, "moveright")){// Right is pressed?
		xdir = V;
    }

	if(playerkeys(iPIndex, 0, "moveup")){// Up is pressed?
		zdir = -V/2;
	} else if(playerkeys(iPIndex, 0, "movedown")){// Down is pressed?
		zdir = V/2;
    }

	changeentityproperty(self, "velocity", xdir, zdir);
}

void keymoveX(float V)
{// Move hero if direction button is pressed in X axis only
	void self 	= getlocalvar("self");
	int iPIndex = getentityproperty(self,"playerindex"); //Get player index
	float xdir 	= 0;
	float zdir 	= getentityproperty(self,"zdir");

    if(playerkeys(iPIndex, 0, "moveleft")){// Left is pressed?
		xdir = -V;
	}else if(playerkeys(iPIndex, 0, "moveright")){// Right is pressed?
		xdir = V;
    }
	
	changeentityproperty(self, "velocity", xdir, zdir);
}

void keymoveZ(float V)
{// Move hero if direction button is pressed in Z axis only
	void self 	= getlocalvar("self");
	int iPIndex = getentityproperty(self,"playerindex"); //Get player index
	float xdir 	= getentityproperty(self,"xdir");
	float zdir 	= 0;

	if(playerkeys(iPIndex, 0, "moveup")){// Up is pressed?
		zdir = -V/2;
	}else if(playerkeys(iPIndex, 0, "movedown")){// Down is pressed?
		zdir = V/2;
	}

	changeentityproperty(self, "velocity", xdir, zdir);
}

void keyflip()
{// Change hero's facing direction if left or right is pressed
	void self 	= getlocalvar("self");
	int iPIndex = getentityproperty(self,"playerindex"); //Get player index

	if(playerkeys(iPIndex, 0, "moveleft")){ // Left is pressed?
		changeentityproperty(self, "direction", 0); //Face left
	}else if(playerkeys(iPIndex, 0, "moveright")){ // Right is pressed?
		changeentityproperty(self, "direction", 1); //Face right
	}
}

// SPAWN - SHOOT///////////////////////////////////////////////////////////////////////////

void spawn01(void vName, float fX, float fY, float fZ)
{	//spawn01 (Generic spawner)
	//Damon Vaughn Caskey
	//07/06/2007
	//
	//Spawns entity next to caller.
	//
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
    //fY: Z location adjustment.

	void self 		= getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	int  iDirection = getentityproperty(self, "direction");

	clearspawnentry(); //Clear current spawn entry.
    setspawnentry("name", vName); //Acquire spawn entity by name.

	if(iDirection == 0){ //Is entity facing left?                  
        fX = -fX; //Reverse X direction to match facing.
	}

    fX = fX + getentityproperty(self, "x"); //Get X location and add adjustment.
    fY = fY + getentityproperty(self, "a"); //Get Y location and add adjustment.
    fZ = fZ + getentityproperty(self, "z"); //Get Z location and add adjustment.
	
	vSpawn = spawn(); //Spawn in entity.

	changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
	changeentityproperty(vSpawn, "direction", iDirection); //Set direction.
    return vSpawn; //Return spawn.
}

void spawner(void vName, float fX, float fY, float fZ)
{	//Spawns entity next to caller and set them as child.
	//
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
    //fY: Z location adjustment.

	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	
	vSpawn = spawn01(vName, fX, fY, fZ); //Spawn in entity.

	changeentityproperty(vSpawn, "parent", self); //Set caller as parent.
    
	return vSpawn; //Return spawn.
}

void spawner2(void vName, float fX, float fY, float fZ)
{	//Spawns entity next to caller with same remap as spawner's. (NINJA DODGE)
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
    //fY: Z location adjustment.

	void self 	= getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	int  iMap 	= getentityproperty(self, "map");

	vSpawn = spawn01(vName, fX, fY, fZ); //Spawn in entity.

	changeentityproperty(vSpawn, "map", iMap); //Use same remap as spawner's.

	return vSpawn; //Return spawn.
}

void baseMap(int index,float rx,float rz,float x_size,float z_size,float min_y,float max_y,float x_cont)
{// Generate Basemaps.

	generatebasemap(index, rx, rz, x_size, z_size, min_y, max_y, x_cont);
}

void shoot(void Shot, float dx, float dy, float dz)
{// Shooting projectile
	void self 		= getlocalvar("self");
	int Direction 	= getentityproperty(self, "direction");
	int x 			= getentityproperty(self, "x");
	int y 			= getentityproperty(self, "a");
	int z 			= getentityproperty(self, "z");
	void vShot;

	if(Direction == 0){ //Is entity facing left?                  
		dx = -dx; //Reverse X direction to match facing
	}

	vShot = projectile(Shot, x+dx, z+dz, y+dy, Direction, 0, 0, 0);
	changeentityproperty(vShot, "parent", self);
	return vShot;
}

void shooter(void Shot, float dx, float dy, float dz, float Vx, float Vy, float Vz)
{// Shooting projectile with speed control
	void vShot = shoot(Shot, dx, dy, dz);

	changeentityproperty(vShot, "velocity", Vx, Vz, Vy);
	changeentityproperty(vShot, "speed", Vx);
}

void shooter2(void Shot, float dx, float dy, float dz, float Vx, float Vy, float Vz)
{// Shooting special projectile with speed control (JACK SPAWN KNIFE)
	void self 		= getlocalvar("self");
	int Direction 	= getentityproperty(self, "direction");
	void vShot;

	if (Direction == 0){ //Is entity facing left?                  
		Vx = -Vx; //Reverse Vx direction to match facing
	}

	vShot = spawn01(Shot, dx, dy, dz);
	changeentityproperty(vShot, "velocity", Vx, Vz, Vy);
	changeentityproperty(vShot, "owner", self);
	return vShot;
}

void shooterB(void Shot, float dx, float dy, float dz)
{// Shooting and bind projectile
	void self = getlocalvar("self");
	void vShot = shoot(Shot, dx, dy, dz);

	bindentity(vShot, self, dx, dz, dy, 0, 0);
}

void throweap(float dx, float dy, float dz, float Vx, float Vy, float Vz)
{// Throw holding weapon with speed control
	void self 	= getlocalvar("self");
	void weapon = getplayerproperty(self, "weapon");
	void vShot 	= shoot(weapon, dx, dy, dz);

	changeentityproperty(vShot, "velocity", Vx, Vz, Vy);
	changeentityproperty(vShot, "speed", Vx);
}

void toss(void Bomb, float dx, float dy, float dz)
{// Tossing bomb
	void self 		= getlocalvar("self");
	int Direction 	= getentityproperty(self, "direction");
	int x 			= getentityproperty(self, "x");
	int y 			= getentityproperty(self, "a");
	int z 			= getentityproperty(self, "z");

	if(Direction == 0){ //Is entity facing left?                  
		dx = -dx; //Reverse X direction to match facing
	}

	projectile(Bomb, x+dx, z+dz, y+dy, Direction, 0, 1, 0);
}

void tosser(void Bomb, float dx, float dy, float dz, float Vx, float Vy, float Vz)
{// Tossing bomb with desired speed
	void self 		= getlocalvar("self");
	int Direction 	= getentityproperty(self, "direction");
	int x 			= getentityproperty(self, "x");
	int y 			= getentityproperty(self, "a");
	int z 			= getentityproperty(self, "z");
	void Shot;

	if(Direction == 0){ //Is entity facing left?                  
		dx = -dx; //Reverse X direction to match facing
	}

	Shot = projectile(Bomb, x+dx, z+dz, y+dy, Direction, 0, 1, 0);
	tossentity(Shot, Vy, Vx, Vz);
	changeentityproperty(Shot, "speed", Vx); 
}

void tosser3(void Bomb, float dx, float dy, float dz, float Vx, float Vy, float Vz)
{// Tossing bomb with desired speed and base 0 (SIGNAL BOTTLE)
	void self 		= getlocalvar("self");
	int Direction 	= getentityproperty(self, "direction");
	int x 			= getentityproperty(self, "x");
	int y 			= getentityproperty(self, "a");
	int z 			= getentityproperty(self, "z");
	void Shot;

	if (Direction == 0){ //Is entity facing left?                  
		dx = -dx; //Reverse X direction to match facing
	}

	Shot = projectile(Bomb, x+dx, z+dz, y+dy, Direction, 0, 0, 0);
	tossentity(Shot, Vy, Vx, Vz);
	changeentityproperty(Shot, "speed", Vx, "projectile", 0); 
	changeentityproperty(Shot, "base", 0);
	changeentityproperty(Shot, "parent", self);
}

void tosser4(void vName, float fX, float fY, float fZ, float fVx, float fVy, float fVz)
{//Spawns entity next to caller and toss it with certain speed. (ITEM DROP)
	void self 		= getlocalvar("self"); //Get calling entity.
	int Direction 	= getentityproperty(self, "direction");
	void vSpawn; //Spawn object.

	vSpawn = spawn01(vName, fX, fY, fZ); //Spawn in entity.

	if(Direction == 0){ //Is entity facing left?                  
		fVx = -fVx; //Reverse fVx direction to match facing
	}

	tossentity(vSpawn, fVy, fVx, fVz); //Toss entity.

	return vSpawn; //Return spawn.
}

void tosser5(void Bomb, float dx, float dy, float dz, float Vx, float Vy, float Vz, int B)
{// Tossing bomb with desired speed and basechange (NINJA JUMP STAR)
	void self 		= getlocalvar("self");
	int Direction 	= getentityproperty(self, "direction");
	int x 			= getentityproperty(self, "x");
	int y 			= getentityproperty(self, "a");
	int z 			= getentityproperty(self, "z");
	void Shot;

	if(Direction == 0){ //Is entity facing left?                  
		dx = -dx; //Reverse X direction to match facing
	}

	Shot = projectile(Bomb, x+dx, z+dz, y+dy, Direction, 0, 0, 0);
	tossentity(Shot, Vy, Vx, Vz);
	changeentityproperty(Shot, "speed", Vx, "projectile", 0); 
	changeentityproperty(Shot, "base", B); 
}

void tosser6(void vName, void Alias, int Map, float fX, float fY, float fZ, float fVx, float fVy, float fVz)
{//Spawns entity next to caller and toss it with certain speed, alias and map (DONOVAN MANHOLE, SIGNAL GATE)
	void self 		= getlocalvar("self"); //Get calling entity.
	void vAlias 	= getentityproperty(self,"name"); // Get caller's alias.
	int iMap 		= getentityproperty(self,"map"); // Get caller's alias.
	int Direction 	= getentityproperty(self, "direction");
	void vSpawn; //Spawn object.

	vSpawn = spawn01(vName, fX, fY, fZ); //Spawn in entity.

	if(Direction == 0){ //Is entity facing left?                  
		fVx = -fVx; //Reverse fVx direction to match facing
	}

	changeentityproperty(vSpawn, "name", Alias); //Set alias.
	changeentityproperty(vSpawn, "map", Map); //Set map.
	tossentity(vSpawn, fVy, fVx, fVz); //Toss entity.

	return vSpawn; //Return spawn.
}

void tosserMP(void Bomb, float dx, float dy, float dz, float Vx, float Vy, float Vz, int MPcost)
{//Tossing bomb with desired speed, base 0 and mpcost (MOTO GRENADE)
	void self 		= getlocalvar("self");
	int MP 			= getentityproperty(self, "mp");
	int Direction 	= getentityproperty(self, "direction");
	int x 			= getentityproperty(self, "x");
	int y 			= getentityproperty(self, "a");
	int z 			= getentityproperty(self, "z");
	void Shot;

	if (Direction == 0){ //Is entity facing left?                  
		dx = -dx; //Reverse X direction to match facing
	}
	
	if(MP >= 1){
		Shot = projectile(Bomb, x+dx, z+dz, y+dy, Direction, 0, 0, 0);
		tossentity(Shot, Vy, Vx, Vz);
		changeentityproperty(Shot, "speed", Vx, "projectile", 0); 
		changeentityproperty(Shot, "base", 0);
		changeentityproperty(self, "mp", MP - MPcost);
	}
}

void tosserX(float fX, float fY, float fZ, float fVx, float fVy, float fVz)
{//Spawns random item next to caller and toss it. //RANDOM ITEM DROP FROM OBSTACLE
	void self 	= getlocalvar("self"); //Get calling entity.
	void vName;
	int Health 	= getentityproperty(self,"health");
    int iR 		= rand()%99;
    	
	if(Health <=0){
	
	if (iR >= 0 && iR <= 2){ 
        vName = "1up";
	} else if (iR >= 3 && iR <= 19){ 
        vName = "Apple";
    } else if (iR >= 20 && iR <= 49){ 
        vName = "Cash";
    } else if (iR >= 50 && iR <= 59){ 
        vName = "Gold";
    } else if (iR >= 60 && iR <= 69){ 
        vName = "Chicken";
	} else if (iR >= 70 && iR <= 79){ 
        vName = "Knife";
	} else if (iR >= 80 && iR <= 89){ 
        vName = "Kunai";
	} else if (iR >= 90 && iR <= 94){ 
        vName = "Sword";
	} else if (iR >= 95 && iR <= 99){ 
        vName = "Pipe";
	} else { 
		vName = "Noitem";
    }

		tosser4(vName, fX, fY, fZ, fVx, fVy, fVz); //Spawn n toss item.
	}
}

void tosserTX(void Bomb, float dx, float dy, float dz, float Vy, float Vz)
{// Tossing bomb with desired Z/Y speed, targetted X speed and base 0 (BIKER BOMB)
	void self 		= getlocalvar("self");
	void target 	= findtarget(self);
	int Direction 	= getentityproperty(self, "direction");
	int x 			= getentityproperty(self, "x");
	int y 			= getentityproperty(self, "a");
	int z 			= getentityproperty(self, "z");
	int Tx 			= getentityproperty(target, "x");
	float xVel;
	void Shot;
	
	xVel = Tx - x;

	if(Direction == 0){ //Is entity facing left?                  
		dx = -dx; //Reverse X direction to match facing
		xVel = -xVel;
	}

	Shot = projectile(Bomb, x+dx, z+dz, y+dy, Direction, 0, 0, 0);
	tossentity(Shot, Vy, xVel/500, Vz);
	changeentityproperty(Shot, "speed", xVel/500, "projectile", 0); 
	changeentityproperty(Shot, "base", 0);
	changeentityproperty(Shot, "parent", self);
}

void spawnbind(void Name, float dx, float dy, float dz)
{// Spawn and bind other entity
	void self = getlocalvar("self");
	void vSpawn;

	vSpawn = spawn01(Name, dx, dy, 0);

	bindentity(vSpawn, self, dx, dz, dy, 0, 0);
	changeentityproperty(vSpawn, "parent", self); //Set caller as parent.

	return vSpawn; //Return vSpawn.
}

void spawnscreen(void Name, float fX, float fY, float fZ)
{//Spawn entity at specific location relative to XPos and YPos
	void self 	= getlocalvar("self"); //Get calling entity.
    int XPos 	= openborvariant("xpos");
	int YPos 	= openborvariant("ypos");
	void vSpawn; //Spawn object.

    fX = fX + XPos; // Changes position relative to XPos
	fY = fY + YPos; // Changes position relative to YPos
	
	vSpawn = spawn01(Name, 0, 0, 0);
	
	changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
    
	return vSpawn; //Return vSpawn.
}

void spawnparent(void Name, float dx, float dy, float dz)
{// Spawn and set to Parent
	void self = getlocalvar("self");
	void vSpawn;

	vSpawn = spawn01(Name, dx, dy, dz);
	changeentityproperty(vSpawn, "parent", self); //Set caller as parent.

	return vSpawn; //Return vSpawn.
}

void spawnAliasP(void Name, void Alias, float dx, float dy, float dz)
{// Spawn and set Alias/Parent (VEHELITS) 
	void self = getlocalvar("self");
	void vSpawn;

	vSpawn = spawn01(Name, dx, dy, dz);

	changeentityproperty(vSpawn, "name", Alias); //Set alias.
	changeentityproperty(vSpawn, "parent", self); //Set caller as parent.

	return vSpawn; //Return vSpawn.
}

void spawnChosen(void Name, int dx, int dy, int dz, int iDirection)
{//Spawn blink cursor in select screen if chosen
	void self 	= getlocalvar("self");
	void vSpawn;
		
	clearspawnentry(); //Clear current spawn entry.
	setspawnentry("name", Name); //Acquire spawn entity by name.

	vSpawn = spawn();	

	changeentityproperty(vSpawn, "position", dx, dz, dy); //Set spawn location.
	changeentityproperty(vSpawn, "direction", iDirection); //Set spawn direction.

	return vSpawn; //Return vSpawn.
}

// CHANGERS///////////////////////////////////////////////////////////////////////////

void anichange(void Ani)
{// Animation changer
	void self = getlocalvar("self");

    changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
}

void subchange(void SubType)
{// Subtype changer
    void self = getlocalvar("self");

    changeentityproperty(self, "subtype", openborconstant(SubType)); //Change SubType
}

void changemodel(void model)
{// Change to weapon model (WEAPON MODELS - JACK SPAWN KNIFE)
	void self = getlocalvar("self");
	
	changeentityproperty(self, "model", model, 1);
}

void resetmodel()
{// Reset model to default (RESET MODEL - JACK THROW KNIFE)
	void self 	= getlocalvar("self");
	void DModel = getentityproperty(self, "defaultmodel");
	
	changeentityproperty(self, "model", DModel, 1);
}

void anichangeP(void AniT, void AniC)
{// Animation changer with Parent caller animation check using spawnbind (JACK SPAWNED KNIFE)
 // AniT: Target animation
 // AniC: self animation to Change
	void self 	= getlocalvar("self");
	void target = getlocalvar("Target" + self);
	void tAniID = getentityproperty(target,"animationID");

	if(target==NULL())
	{
		target = getentityproperty(self, "parent");
		setlocalvar("Target" + self, target);
	}
	if(target!=NULL()){
	   if(tAniID == openborconstant(AniT))
		{
			anichange(AniC);
		}
	}
}

void anichangeMORE(void Ani, int Count) 
{// Animation changer with =/+ ENEMY count (ST7B ELEVATOR)
	void self 	= getlocalvar("self");
	int eCount 	= openborvariant("count_enemies");

	if(eCount >= Count)
	{
		anichange(Ani);
	}
}

void anichangeLESS(void Ani, int Count) 
{// Animation changer with =/- ENEMY count (ST7B ELEVATOR)
	void self 	= getlocalvar("self");
	int eCount 	= openborvariant("count_enemies");

	if(eCount <= Count)
	{
		anichange(Ani);
	}
}

void basechange(int B)
{// Base changer
	void self = getlocalvar("self");

	changeentityproperty(self, "base", B);
}

void degravity(int Ratio)
{// Changes antigravity effect
	void self = getlocalvar("self");

	changeentityproperty(self, "antigravity", Ratio);
}

void block(int Flag)
{// Turns blocking status
	void self = getlocalvar("self");

	if(Flag == 1)
	{
		changeentityproperty(self, "aiflag", "blocking", 1);
		changeentityproperty(self, "takeaction", "common_block");
	} else {
		changeentityproperty(self, "aiflag", "blocking", 0);
	}
}

void jump(int Flag)
{// Turns jumping status (ENEMY JUMPATTACK)
	void self = getlocalvar("self");

	if(Flag == 1)
	{
		changeentityproperty(self, "aiflag", "jumping", 1);
		changeentityproperty(self, "takeaction", "common_jump");
	} else {
		changeentityproperty(self, "aiflag", "jumping", 0);
	}
}

void looper(int Frame, int Limit)
{// Loops current animation
	void self = getlocalvar("self");
	void loop = getlocalvar("Loop" + self);

	if(loop==NULL()){ // Localvar empty?
		setlocalvar("Loop" + self, 0);
		loop = 0;
	}

	if(loop < Limit){ // loops reach limit?
		setlocalvar("Loop" + self, loop+1); // Increment number of loops
		updateframe(self, Frame); //Change frame
	} else if(loop==Limit){ // loops reach limit?
		setlocalvar("Loop" + self, NULL());
	}
}

void beidle()
{// Go to IDLE animation!
	void self = getlocalvar("self");

	setidle(self);
}

void obstacle(int Flag)
{// Turns subject's obstacle status
	void self = getlocalvar("self");

	changeentityproperty(self, "Subject_to_Obstacle", Flag);
}

void screen(int Flag)
{// Turns subject's to screen status
	void self = getlocalvar("self");

	changeentityproperty(self, "Subject_to_Screen", Flag);
}

void wall(int Flag)
{// Turns subject's to wall status
	void self = getlocalvar("self");

	changeentityproperty(self, "Subject_to_Wall", Flag);
}

void platform(int Flag)
{// Turns subject's to platform status
	void self = getlocalvar("self");

	changeentityproperty(self, "Subject_to_Platform", Flag);
}

void minz(int Flag)
{// Turns subject's to minZ status
	void self = getlocalvar("self");

	changeentityproperty(self, "Subject_to_MinZ", Flag);
}

// HURTS///////////////////////////////////////////////////////////////////////////

void offscreenkill(float dx, int E)
{// Check position relative to screen. If enemy is offscreen, suicide!
//	dx : Distance to screen edge
//	E  : Edge selection, 0 = left, 1 = right
	void self 	= getlocalvar("self");
	int x 		= getentityproperty(self,"x"); //Get character's x coordinate
	int XPos 	= openborvariant("xpos"); //Get screen edge's position

	if((x > XPos + 480 + dx) && (E == 1) ){ // Offscreen to the right?
		killentity(self); //Suicide!
	} else if((x < XPos - dx) && (E == 0) ){ // Offscreen to the left?
		killentity(self); //Suicide!
	}
}

void slammed2(int Damage)
{// Hurt self to death
	void self = getlocalvar("self");

	damageentity(self, self, Damage, 1, openborconstant("ATK_NORMAL9")); // Slam damage is inserted here
	tossentity(self, 2, 0, 0);
}

void hurtself(int Damage)
{// Hurt self without toss 
	void self = getlocalvar("self");

	damageentity(self, self, Damage, 0, openborconstant("ATK_NORMAL1")); // Slam damage is inserted here
}

void hurtselfHP(int Limit)
{// Hurt self with minimum HP% check and always max health damage(PARTICLE SUICIDE)
	void self 	= getlocalvar("self");
	int mHealth = getentityproperty(self,"maxhealth"); //Get entity's health
	int Health 	= getentityproperty(self,"health"); //Get entity's health

	if(Health <= mHealth*Limit/100)
	{
		damageentity(self, self, mHealth, 0, openborconstant("ATK_NORMAL1")); // Slam damage is inserted here
	}
}

void riseX()
{// Random rise or riseattack
	void self 	= getlocalvar("self");
	int iR 		= rand()%4;
	 
	if (iR >= 0 && iR <= 4){
		changeentityproperty(self, "animation", openborconstant("ANI_RISEATTACK"));
	}
}

void cancel(int RxMin, int RxMax, int RyMin, int RyMax, int RzMin, int RzMax, void Ani)
{// Attack interruption with range check
	void self 	= getlocalvar("self");
	void target = findtarget(self); //Get nearest player
	float x 	= getentityproperty(self, "x");
	float y 	= getentityproperty(self, "y");
	float z 	= getentityproperty(self, "z");
	int dir 	= getentityproperty(self, "direction");

	if(target!=NULL()){
		float Tx = getentityproperty(target, "x");
		float Ty = getentityproperty(target, "y");
		float Tz = getentityproperty(target, "z");
		float Disx = Tx - x;
		float Disy = Ty - y;
		float Disz = Tz - z;

		if(Disx >= RxMin && Disx <= RxMax && Disy >= RyMin && Disy <= RyMax && Disz >= RzMin && Disz <= RzMax && dir == 1) // Target within range on right facing?
		{
			executeanimation(self, openborconstant(Ani), 1); //Change the animation
		} else if(Disx >= -RxMax && Disx <= -RxMin && Disy >= RyMin && Disy <= RyMax && Disz >= -RzMax && Disz <= -RzMin && dir == 0) // Target within range on left facing?
		{
			executeanimation(self, openborconstant(Ani), 1); //Change the animation
		}
	}
}

void cancelmp(int RxMin, int RxMax, int RyMin, int RyMax, int Limit, void Ani)
{// Enemy attack interruption with range and MP check
	void self 	= getlocalvar("self");
	void target = findtarget(self); //Get nearest player
	float x 	= getentityproperty(self, "x");
	float y 	= getentityproperty(self, "y");
	int MP		= getentityproperty(self, "mp"); //Get entity's MP
	int dir 	= getentityproperty(self, "direction");

	if(target!=NULL()){
		float Tx = getentityproperty(target, "x");
		float Ty = getentityproperty(target, "y");
		float Disx = Tx - x;
		float Disy = Ty - y;

		if(Disx >= RxMin && Disx <= RxMax && Disy >= RyMin && Disy <= RyMax && dir == 1 && MP >= Limit) // Target within range on right facing?
		{
			mpcost(Limit);
			executeanimation(self, openborconstant(Ani), 1); //Change the animation
		} else if(Disx >= -RxMax && Disx <= -RxMin && Disy >= RyMin && Disy <= RyMax && dir == 0 && MP >= Limit) // Target within range on left facing?
		{
			mpcost(Limit);
			executeanimation(self, openborconstant(Ani), 1); //Change the animation
		}
	}
}

void cancelmpX(int RxMin, int RxMax, int RyMin, int RyMax, int Limit, void Ani)
{// Enemy RANDOM attack interruption with range and MP check
    void self 	= getlocalvar("self");
	void target = findtarget(self); //Get nearest player
	float x 	= getentityproperty(self, "x");
	float y 	= getentityproperty(self, "y");
	int MP 		= getentityproperty(self, "mp"); //Get entity's MP
    int dir 	= getentityproperty(self, "direction");
	int iR 		= rand()%4;

    if(target!=NULL()){
		float Tx = getentityproperty(target, "x");
		float Ty = getentityproperty(target, "y");
		float Disx = Tx - x;
		float Disy = Ty - y;
 	
	if(iR >= 0 && iR <= 3){
		if(Disx >= RxMin && Disx <= RxMax && Disy >= RyMin && Disy <= RyMax && dir == 1 && MP >= Limit) // Target within range on right facing?
			{
				mpcost(Limit);
				executeanimation(self, openborconstant(Ani), 1); //Change the animation
			} else if(Disx >= -RxMax && Disx <= -RxMin && Disy >= RyMin && Disy <= RyMax && dir == 0 && MP >= Limit) // Target within range on left facing?
			{
				mpcost(Limit);
				executeanimation(self, openborconstant(Ani), 1); //Change the animation
			}
		}
    }
}

void cancelmpHit(int RxMin, int RxMax, int RyMin, int RyMax, int Limit, void Ani)
{// Enemy attack interruption with range, MP and didhit check (ENEMY RAGE CANCEL)
	void self 	= getlocalvar("self");
	void target = findtarget(self); //Get nearest player
	float x 	= getentityproperty(self, "x");
	float y 	= getentityproperty(self, "y");
	int MP		= getentityproperty(self, "mp"); //Get entity's MP
	int dir 	= getentityproperty(self, "direction");
	int Hit		= getentityproperty(self, "animhits");

	if(target!=NULL()){
		float Tx = getentityproperty(target, "x");
		float Ty = getentityproperty(target, "y");
		float Disx = Tx - x;
		float Disy = Ty - y;

		if(Disx >= RxMin && Disx <= RxMax && Disy >= RyMin && Disy <= RyMax && dir == 1 && MP >= Limit && Hit >= 1) // Target within range on right facing?
		{
			mpcost(Limit);
			changeentityproperty(self, "velocity", 0, 0, 0);
			executeanimation(self, openborconstant(Ani), 1); //Change the animation
		} else if(Disx >= -RxMax && Disx <= -RxMin && Disy >= RyMin && Disy <= RyMax && dir == 0 && MP >= Limit && Hit >= 1) // Target within range on left facing?
		{
			mpcost(Limit);
			changeentityproperty(self, "velocity", 0, 0, 0);
			executeanimation(self, openborconstant(Ani), 1); //Change the animation
		}
	}
}

void cancelfall(void Ani, int Limit, int Cost)
{// Cancel Player Throw or Knockdown Fall if defined button is pressed
    void self	= getlocalvar("self");
    int Health 	= getentityproperty(self,"health");
	int MP 		= getentityproperty(self,"mp"); //Get entity's MP
	int iPIndex = getentityproperty(self,"playerindex");
		
	if(Health > 0){
		if(MP >= Limit){
			if(playerkeys(iPIndex, 0, "jump") && playerkeys(iPIndex, 0, "moveup")){
				mpcost(Cost);
				executeanimation(self, openborconstant(Ani), 1);
			}
		}
	}
}

void cancelfallX(void Ani, int Limit, int Cost)
{// Cancel Enemy Throw or Knockdown Fall RANDOMLY
    void self 	= getlocalvar("self");
  	int Health 	= getentityproperty(self,"health");
	int MP 		= getentityproperty(self,"mp"); //Get entity's MP
	int iR 		= rand()%4;
	
	if(Health >= 1){
		if(MP >= Limit){
			if(iR >= 0 && iR <= 3){
				mpcost(Cost);
				executeanimation(self, openborconstant(Ani), 1);
			}
		}
	}
}

void cancelfallE(void Ani)
{// Cancel Enemy Throw or Knockdown Fall (JET FALL)
	void self 	= getlocalvar("self");
	int Health 	= getentityproperty(self,"health");

	if(Health > 0)
	{
		executeanimation(self, openborconstant(Ani), 1);
	}
}

void landsafe()
{//Alternate safe landing with script
	void self = getlocalvar("self");

	changeentityproperty(self,"damage_on_landing",0);
	changeentityproperty(self,"nograb",0);
	changeentityproperty(self,"aiflag","falling",0);
	changeentityproperty(self,"aiflag","drop",0);
	changeentityproperty(self,"aiflag","projectile",0);
	changeentityproperty(self,"takeaction", "common_attack_proc");
}

void flip()
{// Flip to opposite direction
	void self 	= getlocalvar("self");
	int dir 	= getentityproperty(self,"direction");

	if(dir==0){ // Facing left?
		changeentityproperty(self, "direction", 1);
	} else {
		changeentityproperty(self, "direction", 0);
	}
}

void flipX()
{// Flip to opposite direction randomly (JET LANDSAFE)
    void self 	= getlocalvar("self");
    int dir 	= getentityproperty(self,"direction");
	int iR 		= rand()%4;

	if(iR >= 0 && iR <= 2){
		changeentityproperty(self, "direction", 1);
    } else if(iR >= 3 && iR <= 4){
		changeentityproperty(self, "direction", 0);
    }
}

void mpcost(int Cost)
{// Spend some MP
	void self 	= getlocalvar("self");
	int MP 		= getentityproperty(self,"mp"); //Get entity's MP

	changeentityproperty(self, "mp", MP-Cost); //Spend!
}

void addmp(int Add)
{// Add some MP (MRX RELOAD)
	void self 	= getlocalvar("self");
	int MP 		= getentityproperty(self,"mp");

	changeentityproperty(self, "mp", MP+Add); //Recharge!
}

void suicideP()
{// Suicide if your caller is a Parent and if are dead
	void self 	= getlocalvar("self");
	void target = getlocalvar("Target" + self);
	int THealth = getentityproperty(target, "health");
	
	if(target==NULL())
	{
		target = getentityproperty(self, "parent");
		setlocalvar("Target" + self, target);
	}
	
	if(target!=NULL()){
		if(THealth <= 0)
		{
			killentity(self);
		}
	}
}

void suicideANI(void Ani)
{// Suicide if your caller is a Parent and with a specific Animation
	void self 	= getlocalvar("self");
	void target = getlocalvar("Target" + self);
	void tAniID = getentityproperty(target, "animationID");

	if(target==NULL())
	{
		target = getentityproperty(self, "parent");
		setlocalvar("Target" + self, target);
	}

	if(target!=NULL()){
		if(tAniID == openborconstant(Ani))
		{
			killentity(self);
		}
	}
}

void suicide()
{// Suicide!!
	void self = getlocalvar("self");

	killentity(self); //Suicide!
}

// EFFECTS///////////////////////////////////////////////////////////////////////////

void webmplay(void path, int skip)
{// Play defined webm video
   
	playwebm(path, skip);
}

void sampleplay(void path, int loop)
{// Play defined sample
	void self 	= getlocalvar("self");
	void sample = loadsample(path);

	playsample(openborconstant(sample), 0, 120, 120, 100, loop);
}

void musicplay(void path, int loop)
{//Play defined music
	void self = getlocalvar("self");

	playmusic(path, loop);
}

void shivaMusicX()
{//Play random musics
	void music1 = "data/music/shiva1.ogg";
	void music2 = "data/music/shiva2.ogg";
	void music;
	int  iR 	= rand()%99;

	if(iR >= 0 && iR <= 98){
		music = music2;
	}else{
		music = music1;
	}
		
	playmusic(music, 1);
}

void bossMusicX()
{//Play random musics
	void music1 = "data/music/boss1.ogg";
	void music2 = "data/music/boss2.ogg";
	void music3 = "data/music/boss3.ogg";
	void music;
	int  iR 	= rand()%99;

	if(iR >= 0 && iR <= 49){
		music = music1;
	}else if(iR >= 50 && iR <= 98){
		music = music2;
	}else{
		music = music3;
	}
		
	playmusic(music, 1);
}

void sampleX(void path1, void path2, int loop)
{//Play two random samples (ST1C THUNDER)
	void self 	 = getlocalvar("self");
	void sample1 = loadsample(path1);
	void sample2 = loadsample(path2);
	void sample;
	int  iR 	 = rand()%4;

	if(iR >= 0 && iR <= 3){
		sample = sample1;
	}else{
		sample = sample2;
	}
		
	playsample(openborconstant(sample), 0, 120, 120, 100, loop);
}
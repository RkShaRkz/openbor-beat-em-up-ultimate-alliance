#import "data/scripts/updateentity/main.c"

void main()
{
	posWall();
	nBmap();
}

void posWall()
{// Turns subject's to wall status after hit in the wall
	void self 		= getlocalvar("self");
	void Name 		= getentityproperty(self, "defaultname");
	int Direction 	= getentityproperty(self, "direction");
	int x 			= getentityproperty(self, "x");
	int z 			= getentityproperty(self, "z");
	int nBmap		= openborvariant("numbasemaps");
	int Dist		= 20;
	float H;
	
	if(Direction == 0){ //Is entity facing left?                  
		Dist = -Dist; //Reverse Dist to match facing
	}

	H = checkwall(x-Dist,z);
	
	if(nBmap <= 0){
		if(H > 0){
			changeentityproperty(self, "Subject_to_Wall", 1);
		}else{
			changeentityproperty(self, "Subject_to_Wall", 0);
		}
	}
}
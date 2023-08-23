#import "data/scripts/updateentity/main.c"
#define ANIMATION_NAME "Baby2S"

void main()
{
	rageS();
	grabIdle();
}

void rageS()
{//Shadow copy frame for Rage
    void self   = getlocalvar("self");
    void vAniID = getentityproperty(self, "animationID");
    int Frame   = getentityproperty(self, "animpos");
    int rate    = 4; //YOU CAN FREELY ADJUST THE RATE IF IT'S NECESSARY
    void vSpawn;
    
    if(openborvariant("elapsed_time")%rate == 0)
    {
        if(vAniID == openborconstant("ANI_FREESPECIAL"))
        {
            vSpawn = spawn01(ANIMATION_NAME, 0, 0, -1);
            changeentityproperty(vSpawn, "parent", self);
            updateframe(vSpawn, Frame);
        }
    }
}

void grabIdle()
{//Set idle if no grab
	void self 	= getlocalvar("self");
	void target = getentityproperty(self, "grabbing");
	void vAniID = getentityproperty(self, "animationID");

	if(vAniID == openborconstant("ANI_GRABATTACK")){
		if(target == NULL())
		{
			setidle(self);
		}
	}
}
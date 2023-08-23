#import "data/scripts/updateentity/main.c"
#define ANIMATION_NAME "FunkManS"

void main()
{
	rageS();
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
        if(vAniID == openborconstant("ANI_FREESPECIAL3"))
        {
            vSpawn = spawn01(ANIMATION_NAME, 0, 0, -1);
            changeentityproperty(vSpawn, "parent", self);
	    changeentityproperty(vSpawn, "animation", openborconstant("ANI_IDLE"));
            updateframe(vSpawn, Frame);
        }
    }
}
#import "data/scripts/updateentity/main.c"
#define ANIMATION_NAME "JetS"

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
        if(vAniID == openborconstant("ANI_FOLLOW3"))
        {
            vSpawn = spawn01(ANIMATION_NAME, 0, 0, -1);
            changeentityproperty(vSpawn, "parent", self);
	    changeentityproperty(vSpawn, "animation", openborconstant("ANI_IDLE"));
            updateframe(vSpawn, Frame);
        }
        else if(vAniID == openborconstant("ANI_FOLLOW4"))
        {
            vSpawn = spawn01(ANIMATION_NAME, 0, 0, -1);
            changeentityproperty(vSpawn, "parent", self);
	    changeentityproperty(vSpawn, "animation", openborconstant("ANI_IDLE2"));
            updateframe(vSpawn, Frame);
        }
    }
}
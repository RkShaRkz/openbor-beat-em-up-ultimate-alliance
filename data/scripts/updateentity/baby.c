#import "data/scripts/updateentity/main.c"

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
        if(vAniID == openborconstant("ANI_IDLE"))
        {
            vSpawn = spawn01("BabyS", 0, 0, -1);
            changeentityproperty(vSpawn, "parent", self);
            updateframe(vSpawn, Frame);
        }
    }
}
void main()
{
	cancelLandAtk();
}

void cancelLandAtk()
{//Cancel land animation with Short Range Charge Attack
    void self 	= getlocalvar("self");
	void vAniID = getentityproperty(self,"animationID");
	int iPIndex = getentityproperty(self,"playerindex");
	
	if(playerkeys(iPIndex, 1, "jump")){
		if(vAniID == openborconstant("ANI_IDLE"))
		{
			changeentityproperty(self, "velocity", 0, 0, 0);
			performattack(self, openborconstant("ANI_FREESPECIAL2"), 0);
		}
		if(vAniID == openborconstant("ANI_WALK"))
		{
			changeentityproperty(self, "velocity", 0, 0, 0);
			performattack(self, openborconstant("ANI_FREESPECIAL2"), 0);
		}
		if(vAniID == openborconstant("ANI_RUN"))
		{
			changeentityproperty(self, "velocity", 0, 0, 0);
			performattack(self, openborconstant("ANI_FREESPECIAL2"), 0);
		}
		if(vAniID == openborconstant("ANI_LAND"))
		{
			changeentityproperty(self, "velocity", 0, 0, 0);
			performattack(self, openborconstant("ANI_FREESPECIAL2"), 0);
		}
	}
}
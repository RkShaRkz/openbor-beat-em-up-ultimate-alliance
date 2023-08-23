void main()
{
	dodge();
	rageCancel();
}

void dodge()
{//DODGE
    void self 	= getlocalvar("self");
	void vAniID = getentityproperty(self,"animationID");
	int iPIndex = getentityproperty(self,"playerindex");
	
	if(playerkeys(iPIndex, 1, "attack3")){
		if(vAniID == openborconstant("ANI_WALK"))
		{
			changeentityproperty(self, "velocity", 0, 0, 0);
			executeanimation(self, openborconstant("ANI_FOLLOW1"), 0);
		} else if(vAniID == openborconstant("ANI_RUN"))
		{
			changeentityproperty(self, "velocity", 0, 0, 0);
			executeanimation(self, openborconstant("ANI_FOLLOW1"), 0);
		}
	}
}

void rageCancel()
{//Cancel defined moves with Rage Special
    void self 	= getlocalvar("self");
	void vAniID = getentityproperty(self,"animationID");
	int iPIndex = getentityproperty(self,"playerindex");
	int Frame	= getentityproperty(self,"animpos");
	int Hit		= getentityproperty(self,"animhits");
	int MaxMP	= getentityproperty(self,"maxmp");
	int MP		= getentityproperty(self,"mp");
	int CostMp	= MaxMP;
	
	if(playerkeys(iPIndex, 1, "attack2") && MP >= CostMp){
		if(vAniID == openborconstant("ANI_RUN"))
		{
			mpcost(CostMp);
			changeentityproperty(self, "velocity", 0, 0, 0);
			performattack(self, openborconstant("ANI_FREESPECIAL5"), 0);
		} else if(vAniID == openborconstant("ANI_RUNATTACK")){
			if(Frame >= 4 && Frame <= 7 && Hit >= 1)
			{
				mpcost(CostMp);
				changeentityproperty(self, "velocity", 0, 0, 0);
				performattack(self, openborconstant("ANI_FREESPECIAL5"), 0);
			}
		}
	}
}

void mpcost(int Cost)
{// Spend some MP
	void self 	= getlocalvar("self");
	int MP 		= getentityproperty(self,"mp"); //Get entity's MP

	changeentityproperty(self, "mp", MP-Cost); //Spend!
}
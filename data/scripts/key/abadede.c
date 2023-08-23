void main()
{
	rageCancel();
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
		if(vAniID == openborconstant("ANI_ATTACK2")){
			if(Frame >= 4 && Frame <= 5 && Hit >= 1)
			{
				mpcost(CostMp);
				changeentityproperty(self, "velocity", 0, 0, 0);
				performattack(self, openborconstant("ANI_FREESPECIAL3"), 0);
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
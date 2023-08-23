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
		if(vAniID == openborconstant("ANI_ATTACK1")){
			if(Frame >= 2 && Frame <= 3 && Hit >= 1)
			{
				mpcost(CostMp);
				performattack(self, openborconstant("ANI_FREESPECIAL6"), 0);
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
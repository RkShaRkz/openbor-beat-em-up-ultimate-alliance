void main()
{
	dodge();
	rageCancel();
	specialCancel();
}

void dodge()
{//DODGE
    void self 	= getlocalvar("self");
	void vAniID = getentityproperty(self,"animationID");
	void vModel	= getentityproperty(self,"model");
	int iPIndex = getentityproperty(self,"playerindex");
	
	if(playerkeys(iPIndex, 1, "attack3")){
		if(vModel == "Blaze"){
			if(vAniID == openborconstant("ANI_WALK"))
			{
				executeanimation(self, openborconstant("ANI_FOLLOW1"), 0);
			} else if(vAniID == openborconstant("ANI_RUN"))
			{
				executeanimation(self, openborconstant("ANI_FOLLOW1"), 0);
			}
		}
	}
}

void rageCancel()
{//Cancel defined moves with Rage Special
    void self 	= getlocalvar("self");
	void vAniID = getentityproperty(self,"animationID");
	void vModel	= getentityproperty(self,"model");
	int grab	= getentityproperty(self,"grabbing");
	int iPIndex = getentityproperty(self,"playerindex");
	int Frame	= getentityproperty(self,"animpos");
	int Hit		= getentityproperty(self,"animhits");
	int MHealth	= getentityproperty(self,"maxhealth");
	int Health	= getentityproperty(self,"health");
	int MaxMP	= getentityproperty(self,"maxmp");
	int MP		= getentityproperty(self,"mp");
	int CostHp	= MHealth/5;
	int CostMp	= MaxMP;
	
	if(playerkeys(iPIndex, 1, "attack2") && MP >= CostMp && grab == NULL()){
		if(vModel == "Blaze"){
			if(vAniID == openborconstant("ANI_WALK"))
			{
				mpcost(CostMp);
				changeentityproperty(self, "velocity", 0, 0, 0);
				performattack(self, openborconstant("ANI_FREESPECIAL"), 0);
			} else if(vAniID == openborconstant("ANI_RUN"))
			{
				mpcost(CostMp);
				changeentityproperty(self, "velocity", 0, 0, 0);
				performattack(self, openborconstant("ANI_FREESPECIAL"), 0);
			} else if(vAniID == openborconstant("ANI_ATTACK3")){
				if(Frame >= 2 && Frame <= 6 && Hit >= 1)
				{
					mpcost(CostMp);
					performattack(self, openborconstant("ANI_FREESPECIAL"), 0);
				}
			}
		}
	}else if(playerkeys(iPIndex, 1, "attack2") && MP >= 80 && MP <= 119 && Health > CostHp && grab == NULL()){
		if(vModel == "Blaze"){
			if(vAniID == openborconstant("ANI_IDLE"))
			{
				hpcost(CostHp);
				mpcost(CostMp);
				performattack(self, openborconstant("ANI_FREESPECIAL"), 0);
			} else if(vAniID == openborconstant("ANI_WALK"))
			{
				hpcost(CostHp);
				mpcost(CostMp);
				changeentityproperty(self, "velocity", 0, 0, 0);
				performattack(self, openborconstant("ANI_FREESPECIAL"), 0);
			} else if(vAniID == openborconstant("ANI_RUN"))
			{
				hpcost(CostHp);
				mpcost(CostMp);
				changeentityproperty(self, "velocity", 0, 0, 0);
				performattack(self, openborconstant("ANI_FREESPECIAL"), 0);
			} else if(vAniID == openborconstant("ANI_ATTACK3")){
				if(Frame >= 2 && Frame <= 6 && Hit >= 1)
				{
					hpcost(CostHp);
					mpcost(CostMp);
					performattack(self, openborconstant("ANI_FREESPECIAL"), 0);
				}
			} else if(vAniID == openborconstant("ANI_SPECIAL2")){
				if(Frame >= 1 && Frame <= 13 && Hit >= 1)
				{
					hpcost(CostHp);
					mpcost(CostMp);
					performattack(self, openborconstant("ANI_FREESPECIAL"), 0);
				}
			}
		}
	}
}

void specialCancel()
{//Cancel defined moves with Offensive Special
    void self 	= getlocalvar("self");
	void vAniID = getentityproperty(self,"animationID");
	int grab	= getentityproperty(self,"grabbing");
	int iPIndex = getentityproperty(self,"playerindex");
	int Frame	= getentityproperty(self,"animpos");
	int Hit		= getentityproperty(self,"animhits");
	int MaxMP	= getentityproperty(self,"maxmp");
	int MP		= getentityproperty(self,"mp");
	int CostMp	= MaxMP/3;
	
	if(playerkeys(iPIndex, 1, "special") && playerkeys(iPIndex, 0, "moveleft") && MP >= CostMp && grab == NULL() || playerkeys(iPIndex, 1, "special") && playerkeys(iPIndex, 0, "moveright") && MP >= CostMp && grab == NULL()){
		if(vAniID == openborconstant("ANI_WALK"))
		{
			mpcost(CostMp);
			changeentityproperty(self, "velocity", 0, 0, 0);
			performattack(self, openborconstant("ANI_SPECIAL2"), 0);
		} else if(vAniID == openborconstant("ANI_RUN"))
		{
			mpcost(CostMp);
			changeentityproperty(self, "velocity", 0, 0, 0);
			performattack(self, openborconstant("ANI_SPECIAL2"), 0);
		} else if(vAniID == openborconstant("ANI_ATTACK3")){
			if(Frame >= 2 && Frame <= 6 && Hit >= 1)
			{
				mpcost(CostMp);
				performattack(self, openborconstant("ANI_SPECIAL2"), 0);
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

void hpcost(int Cost)
{// Spend some MP
	void self 	= getlocalvar("self");
	int Health	= getentityproperty(self,"health"); //Get entity's Health

	changeentityproperty(self, "health", Health-Cost); //Spend!
}
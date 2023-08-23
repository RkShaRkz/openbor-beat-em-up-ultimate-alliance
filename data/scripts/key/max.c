void main()
{
	dodge();
	rageCancel();
	specialCancel();
	grabCancel();
}

void dodge()
{//DODGE
    void self 	= getlocalvar("self");
	void vAniID = getentityproperty(self,"animationID");
	void vModel	= getentityproperty(self,"model");
	int iPIndex = getentityproperty(self,"playerindex");
	
	if(playerkeys(iPIndex, 1, "attack3")){
		if(vModel == "Max"){
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
	int iPIndex = getentityproperty(self,"playerindex");
	int Frame	= getentityproperty(self,"animpos");
	int Hit		= getentityproperty(self,"animhits");
	int MHealth	= getentityproperty(self,"maxhealth");
	int Health	= getentityproperty(self,"health");
	int MaxMP	= getentityproperty(self,"maxmp");
	int MP		= getentityproperty(self,"mp");
	int CostHp	= MHealth/5;
	int CostMp	= MaxMP;
	
	if(playerkeys(iPIndex, 1, "attack2") && MP >= CostMp){
		if(vModel == "Max"){
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
			} else if(vAniID == openborconstant("ANI_GRAB"))
			{
				mpcost(CostMp);
				performattack(self, openborconstant("ANI_FREESPECIAL"), 0);
			} else if(vAniID == openborconstant("ANI_ATTACK3")){
				if(Frame >= 3 && Frame <= 4 && Hit >= 1)
				{
					mpcost(CostMp);
					performattack(self, openborconstant("ANI_FREESPECIAL"), 0);
				}
			} else if(vAniID == openborconstant("ANI_RUNATTACK")){
				if(Frame >= 2 && Frame <= 3 && Hit >= 1)
				{
					mpcost(CostMp);
					changeentityproperty(self, "velocity", 0, 0, 0);
					performattack(self, openborconstant("ANI_FREESPECIAL"), 0);
				}
			}
		}
	}else if(playerkeys(iPIndex, 1, "attack2") && MP >= 80 && MP <= 119 && Health > CostHp){
		if(vModel == "Max"){
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
			} else if(vAniID == openborconstant("ANI_GRAB"))
			{
				hpcost(CostHp);
				mpcost(CostMp);
				performattack(self, openborconstant("ANI_FREESPECIAL"), 0);
			} else if(vAniID == openborconstant("ANI_ATTACK3")){
				if(Frame >= 3 && Frame <= 4 && Hit >= 1)
				{
					hpcost(CostHp);
					mpcost(CostMp);
					performattack(self, openborconstant("ANI_FREESPECIAL"), 0);
				}
			} else if(vAniID == openborconstant("ANI_RUNATTACK")){
				if(Frame >= 2 && Frame <= 3 && Hit >= 1)
				{
					hpcost(CostHp);
					mpcost(CostMp);
					changeentityproperty(self, "velocity", 0, 0, 0);
					performattack(self, openborconstant("ANI_FREESPECIAL"), 0);
				}
			} else if(vAniID == openborconstant("ANI_SPECIAL2")){
				if(Frame >= 2 && Frame <= 7 && Hit >= 1)
				{
					hpcost(CostHp);
					mpcost(CostMp);
					changeentityproperty(self, "velocity", 0, 0, 0);
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
	int iPIndex = getentityproperty(self,"playerindex");
	int MaxMP	= getentityproperty(self,"maxmp");
	int MP		= getentityproperty(self,"mp");
	int CostMp	= MaxMP/3;
	
	if(playerkeys(iPIndex, 1, "special") && playerkeys(iPIndex, 0, "moveleft") && MP >= CostMp || playerkeys(iPIndex, 1, "special") && playerkeys(iPIndex, 0, "moveright")&& MP >= CostMp){
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
		} else if(vAniID == openborconstant("ANI_GRAB"))
		{
			mpcost(CostMp);
			performattack(self, openborconstant("ANI_SPECIAL2"), 0);
		}
	}
}

void grabCancel()
{//Cancel Grab with throw or slam
    void self 	= getlocalvar("self");
	void vAniID = getentityproperty(self,"animationID");
	int iPIndex = getentityproperty(self,"playerindex");
	int Frame	= getentityproperty(self,"animpos");
	
	if(playerkeys(iPIndex, 1, "attack")){
		if(vAniID == openborconstant("ANI_GRABATTACK2") && Frame == 1)
		{
			performattack(self, openborconstant("ANI_GRABUP2"), 0);
		} else if(vAniID == openborconstant("ANI_GRABATTACK2") && Frame == 3)
		{
			performattack(self, openborconstant("ANI_GRABDOWN2"), 0);
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
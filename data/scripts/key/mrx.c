void main()
{
	diagonalShoot();
	downShoot();
}

void diagonalShoot()
{//Custom shoot direction
    void self 	= getlocalvar("self");
	void vAniID = getentityproperty(self,"animationID");
	int iPIndex = getentityproperty(self,"playerindex");
	int MaxMP	= getentityproperty(self,"maxmp");
	int MP		= getentityproperty(self,"mp");
	int CostMp	= MaxMP/5;
	
	if(playerkeys(iPIndex, 1, "attack") && playerkeys(iPIndex, 0, "moveleft") && playerkeys(iPIndex, 0, "movedown") && MP >= CostMp ||
	   playerkeys(iPIndex, 1, "attack") && playerkeys(iPIndex, 0, "moveright")&& playerkeys(iPIndex, 0, "movedown") && MP >= CostMp){
		if(vAniID == openborconstant("ANI_WALK"))
		{
			mpcost(CostMp);
			changeentityproperty(self, "velocity", 0, 0, 0);
			performattack(self, openborconstant("ANI_FREESPECIAL2"), 0);
		}
	}
}

void downShoot()
{//Custom shoot direction
    void self 	= getlocalvar("self");
	void vAniID = getentityproperty(self,"animationID");
	int iPIndex = getentityproperty(self,"playerindex");
	int MaxMP	= getentityproperty(self,"maxmp");
	int MP		= getentityproperty(self,"mp");
	int CostMp	= MaxMP/5;
	
	if(playerkeys(iPIndex, 1, "attack")&& playerkeys(iPIndex, 0, "movedown") && MP >= CostMp){
		if(vAniID == openborconstant("ANI_WALK"))
		{
			mpcost(CostMp);
			changeentityproperty(self, "velocity", 0, 0, 0);
			performattack(self, openborconstant("ANI_FREESPECIAL3"), 0);
		}
	}
}

void mpcost(int Cost)
{// Spend some MP
	void self 	= getlocalvar("self");
	int MP 		= getentityproperty(self,"mp"); //Get entity's MP

	changeentityproperty(self, "mp", MP-Cost); //Spend!
}
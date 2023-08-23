#import "data/scripts/didblock/main.c"

void main()
{
	counter();
	guardCost();
}

void counter()
{//COUNTER
    void self 	= getlocalvar("self");
	int iPIndex = getentityproperty(self, "playerindex");
	int Gp		= getentityproperty(self, "guardpoints");
	int iR 		= rand()%4;
	
	if (iR >= 1 && iR <= 4 && Gp >= 80)
		{
			performattack(self, openborconstant("ANI_SPECIAL"), 1);
			spawnbind("counter", 0, 0, 1);
			changeentityproperty(self, "guardpoints", Gp-80);
		}
}
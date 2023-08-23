void main()
{
	void self 		= getlocalvar("self");
	void vRName 	= getentityproperty(self,"defaultname"); // Get caller's real name.
	void vAlias		= getentityproperty(self,"name"); // Get caller's alias.
	int  iMHealth 	= getentityproperty(self,"maxhealth"); // Get caller's maxhealth.
	int  iHealth 	= getentityproperty(self,"health"); // Get caller's health.
	int  iAggre 	= getentityproperty(self,"aggression"); // Get caller's aggression.
	int  iScore 	= getentityproperty(self,"score"); // Get caller's score.
	int  iMap 		= getentityproperty(self,"map"); // Get caller's map.
	int  pCount		= openborvariant("count_players"); // Count players alive.
	int  Add		= 400*pCount; //Each active player add more Health to him
	int  set		= openborvariant("current_set");
	
	if(set == 2 || set == 3)
	{
		changeentityproperty(self, "nodieblink", 3);
	}
	
	if(vRName == "Zamza0"){
		vAlias		= "Zamza";
		iMHealth	= 400+Add;
		iHealth 	= iMHealth;
		iAggre 		= 1500;
		iScore 		= 40000;
		iMap		= 0;
	}else if(vRName == "Zamza1"){
		vAlias		= "Souther";
		iMHealth	= 400+Add;
		iHealth 	= iMHealth;
		iAggre 		= 1500;
		iScore 		= 40000;
		iMap		= 1;
	}else if(vRName == "Zamza2"){
		vAlias		= "Nail";
		iMHealth	= 400+Add;
		iHealth 	= iMHealth;
		iAggre 		= 1500;
		iScore 		= 40000;
		iMap		= 2;
	}
	
	changeentityproperty(self, "name", vAlias); //Set alias.
	changeentityproperty(self, "maxhealth", iMHealth); //Set maxhealth.
	changeentityproperty(self, "health", iHealth); //Set health.
	changeentityproperty(self, "aggression", iAggre); //Set aggression.
	changeentityproperty(self, "score", iScore); //Set score.
	changeentityproperty(self, "map", iMap); //Set map.
}
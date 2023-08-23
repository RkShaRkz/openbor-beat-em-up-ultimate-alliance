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
	int  set		= openborvariant("current_set");
	
	if(set == 2 || set == 3)
	{
		changeentityproperty(self, "nodieblink", 3);
	}
	
	if(vRName == "Particle0"){
		vAlias		= "Particle";
		iMHealth	= 1400;
		iHealth 	= iMHealth;
		iAggre 		= 1500;
		iScore 		= 40000;
		iMap		= 0;
	}else if(vRName == "Particle1"){
		vAlias		= "Oxygen";
		iMHealth	= 1400;
		iHealth 	= iMHealth;
		iAggre 		= 1500;
		iScore 		= 40000;
		iMap		= 1;
	}else if(vRName == "Particle2"){
		vAlias		= "Molecule";
		iMHealth	= 1400;
		iHealth 	= iMHealth;
		iAggre 		= 1500;
		iScore 		= 40000;
		iMap		= 2;
	}else if(vRName == "Particle3"){
		vAlias		= "Uranium";
		iMHealth	= 1400;
		iHealth 	= iMHealth;
		iAggre 		= 1500;
		iScore 		= 40000;
		iMap		= 3;
	}
	
	changeentityproperty(self, "name", vAlias); //Set alias.
	changeentityproperty(self, "maxhealth", iMHealth); //Set maxhealth.
	changeentityproperty(self, "health", iHealth); //Set health.
	changeentityproperty(self, "aggression", iAggre); //Set aggression.
	changeentityproperty(self, "score", iScore); //Set score.
	changeentityproperty(self, "map", iMap); //Set map.
}
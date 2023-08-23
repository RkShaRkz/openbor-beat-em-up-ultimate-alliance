void modelcopy()
{// Maintain default header config for alternative models (WEAPON MODELS)

    void self		= getlocalvar("self");
	void old 		= getlocalvar("old");
	void vAlias 	= getentityproperty(old,"name"); // Get caller's alias.
	int  iMHealth 	= getentityproperty(old,"maxhealth"); // Get caller's maxhealth.
	int  iHealth 	= getentityproperty(old,"health"); // Get caller's health.
	int  iSpeed 	= getentityproperty(old,"speed"); // Get caller's speed.
	int  iAggre 	= getentityproperty(old,"aggression"); // Get caller's aggression.
	int  iScore 	= getentityproperty(old,"score"); // Get caller's score.
	int  iMap 		= getentityproperty(old,"map"); // Get caller's map.
	int  iSubW 		= getentityproperty(old,"subject_to_wall"); // Get caller's to wall.
	int  iGuard		= getentityproperty(old,"guardpoints"); // Get caller's to wall.
	int  iBlink		= getentityproperty(old,"nodieblink"); // Get caller's blink status.

	changeentityproperty(self, "name", vAlias); //Set alias.
    changeentityproperty(self, "maxhealth", iMHealth); //Set maxhealth.
	changeentityproperty(self, "health", iHealth); //Set health.
	changeentityproperty(self, "speed", iSpeed); //Set speed.
	changeentityproperty(self, "aggression", iAggre); //Set aggression.
	changeentityproperty(self, "score", iScore); //Set score.
	changeentityproperty(self, "map", iMap); //Set map.
	changeentityproperty(self, "subject_to_wall", iSubW); //Set subject_to_wall's flag.
	changeentityproperty(self, "guardpoints", iGuard); //Set guardpoints.
	changeentityproperty(self, "nodieblink", iBlink); //Set nodieblink status.
}
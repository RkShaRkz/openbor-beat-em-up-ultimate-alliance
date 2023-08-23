void main()
{// Reload Mrx weapon
    void self 	= getlocalvar("self");
	void Ani 	= getentityproperty(self, "animationID");
	int Mp 		= getentityproperty(self, "mp");
	int Height	= getentityproperty(self, "y");
	
	if(Mp == 0){
		if(Height == 0){
			if(Ani == openborconstant("ANI_WALK"))
			{
				executeanimation(self, openborconstant("ANI_FOLLOW6"), 1);
			}
		}
	}
}
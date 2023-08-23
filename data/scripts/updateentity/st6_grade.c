void main()
{
	void self = getlocalvar("self");
	
	if(openborvariant("xpos") >= 200){
		killentity(self);
	}
}

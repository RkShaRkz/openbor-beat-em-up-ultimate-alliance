void main()
{//Adjust camera with XPOS check

	if(openborvariant("xpos") >= 1){
		changelevelproperty("camerazoffset", 0);
	}
}
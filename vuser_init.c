vuser_init()
{

	web_reg_save_param_ex(
    	"ParamName=userSession", 
    	"LB/IC=name=\"userSession\" value=\"",
   		"RB/IC=\"",
   	 	"Ordinal=1",
	LAST);

	web_url("WebTours", 
		"URL={Host}/WebTours", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	/* Login */

	web_submit_data("login.pl",
		"Action={Host}/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer={Host}/cgi-bin/nav.pl?in=home",
		"Snapshot=t2.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={username}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=login.x", "Value=50", ENDITEM,
		"Name=login.y", "Value=13", ENDITEM,
		LAST);

	
	return 0;
}

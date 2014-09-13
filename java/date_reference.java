// java.util.*

// Date pra string e vice-versa:
SimpleDateFormat sdf = new SimpleDateFormat("dd-M-yyyy hh:mm:ss");
String dateInString = "31-08-1982 10:20:56";
Date date = sdf.parse(dateInString);
String date = sdf.format(new Date()); 

// GregorianCalendar
Calendar cal = new GregorianCalendar(2013,0,31);
int year = cal.get(Calendar.YEAR); // cal.set(Calendar.CONST, val)
MONTH, DAY_OF_MONTH, DAY_OF_WEEK, WEEK_OF_YEAR, WEEK_OF_MONTH
HOUR /*12 hour clock*/ HOUR_OF_DAY /*24 hour clock*/
MINUTE, SECOND, MILLISECOND, DAY_OF_YEAR, ERA /*AD,BC*/,
AM_PM

/*
Let the date be Y, M, D, where Y is the AD year, M is the month (January=1, December=12), and D is the day (1-31).
For the following calculations, use integer arithmetic (i.e. lop off the fractional part of any result).

If M==1 or M==2 then Y--, M+=12.
Let A = Y/100
Let B = A/4
Let C = 2-A-B (or C=0 if you're using the Julian calendar)
Let E = 365.25*(Y+4716)
Let F = 30.6001*(M+1)

Julian Day = C+D+E+F-1524.5 , ou sem o .5 pra meia noite*/
long j1 = julian_day(c1.get(YEAR), c1.get(MONTH)+1, c1.get(DAY));
long j2 = julian_day(c2.get(YEAR), c2.get(MONTH)+1, c2.get(DAY));
long days_elapsed = j2-j1;

cal.add((GregorianCalendar.MONTH), 2); // -2 to subtract
Date d = cal.getTime(); long mili = d.getTime();
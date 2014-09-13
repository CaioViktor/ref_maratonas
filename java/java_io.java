import java.io.*;
import java.util.*;

BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
String line;
StringTokenizer idata;
while ((line = bi.readLine()) != null) {
	idata = new StringTokenizer(line);
	while (idata.hasMoreTokens()) {
		num = Integer.parseInt(idata.nextToken());
		// ...
	}
}
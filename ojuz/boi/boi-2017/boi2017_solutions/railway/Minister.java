import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Minister {
    
	// ------------ INPUT HANDLING
	static BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st = new StringTokenizer("");
	
    // Read next input-token as integer.
    static int readInt() throws Exception {
        return Integer.parseInt(readString());
    }
    
    // Read next input-token as string.
    static String readString() throws Exception {
        while (!st.hasMoreTokens()) {
            st = new StringTokenizer(stdin.readLine());
        }
        return st.nextToken();
    }
    
    // ------------ END INPUT HANDLING

    static int n, m, k;

    // 	indexed by vertices 0...n-1
    static ArrayList<ArrayList<Integer> > T;
    static ArrayList<ArrayList<Integer> > ID;
    static ArrayList<ArrayList<Integer> > ministersInCity;
    static ArrayList<Integer> biggestChild; 
    static ArrayList<Integer> passiveMinisters; 
    static ArrayList<Boolean> onDFSStack; 
        
    // indexed by ministers 0...m-1
    static ArrayList<Integer> ministerNumCities; 
    
    // answer
    static ArrayList<Integer> importantTracks;
    
    public static void initialize() throws Exception {
    	
    	n = readInt();
    	m = readInt();
    	k = readInt();

    	passiveMinisters = new ArrayList<Integer> (Collections.nCopies(n, 0));
    	biggestChild = new ArrayList<Integer> (Collections.nCopies(n, -1));
    	onDFSStack = new ArrayList<Boolean> (Collections.nCopies(n, false));
    	
    	T = new ArrayList<ArrayList<Integer> > ();
    	ID = new ArrayList<ArrayList<Integer> > ();
    	ministersInCity = new ArrayList<ArrayList<Integer> > ();
    	for(int i = 0; i < n; ++i) {
    		T.add(new ArrayList<Integer>());
    		ID.add(new ArrayList<Integer> ());
    		ministersInCity.add(new ArrayList<Integer>());
    	}
    		
    	for(int i = 1; i <= n-1; ++i) {
    		int u = readInt() - 1;
    		int v = readInt() - 1;
    		T.get(u).add(v);
    		T.get(v).add(u);
    		ID.get(u).add(i);
    		ID.get(v).add(i);
    	}
    	
    	ministerNumCities = new ArrayList<Integer> (Collections.nCopies(m, 0)); 
    	for(int i = 0; i < m; ++i) {
    		int si = readInt();
    		ministerNumCities.set(i, si);

    		for(int j = 0; j < si; ++j) {
    			int city = readInt() - 1;
    			ministersInCity.get(city).add(i);
    		}
   		}
    	
    	importantTracks = new ArrayList<Integer> ();
    }
    
    
    // when this is over biggestChild[pos] = u for child u with largest subtree. 
    public static int makeBiggestChildDFS(int pos) {
    	onDFSStack.set(pos, true);
    	int biggestSize = -1;
    	int myBiggestChild = -1;
    	int ans = 1;
    	for(int ch : T.get(pos)) {
    		if(onDFSStack.get(ch)) continue;
    		int mySize = makeBiggestChildDFS(ch);
    		ans += mySize;
    		if(biggestSize < mySize) {
    			biggestSize = mySize;
    			myBiggestChild = ch;
    		}
    	}
    	biggestChild.set(pos, myBiggestChild);
    	onDFSStack.set(pos, false);
    	return ans;
    }
    
    // returns for each minister below the tree how many times he appears below the tree
    // sets passive-ministers = number of ministers that have appeared entirely in the subtree
    // counts the number of important edges
    public static HashMap<Integer, Integer> DFS(int pos, int edgeID) {
    	HashMap<Integer, Integer> ans = new HashMap<Integer, Integer> ();
  
    	onDFSStack.set(pos, true);
    	ArrayList<HashMap<Integer, Integer> > chMaps = new ArrayList<HashMap<Integer, Integer> > ();
    	for(int i = 0; i < T.get(pos).size(); ++i) {
    		int ch = T.get(pos).get(i);
    		int chID = ID.get(pos).get(i);

    		if(onDFSStack.get(ch)) continue;
    		
    		if(ch == biggestChild.get(pos)) {
    			ans = DFS(ch, chID);
    			passiveMinisters.set(pos, passiveMinisters.get(ch));
    		} else { 
    			chMaps.add(DFS(ch, chID));
    	}}
    	
    	for(HashMap<Integer, Integer> addMap : chMaps) {
    		for(int minister : addMap.keySet()) {
    			if(!ans.containsKey(minister)) {ans.put(minister, addMap.get(minister));} else {ans.put(minister, ans.get(minister) + addMap.get(minister));}
    			if(ans.get(minister).equals(ministerNumCities.get(minister))) {passiveMinisters.set(pos, passiveMinisters.get(pos) + 1);}
    		}
    	}
    	
    	for(int minister : ministersInCity.get(pos)) {
			if(!ans.containsKey(minister)) {ans.put(minister, 1);} else {ans.put(minister, ans.get(minister) + 1);}
			if(ans.get(minister).equals(ministerNumCities.get(minister))) passiveMinisters.set(pos, passiveMinisters.get(pos) + 1);
		}
    	
    	if(ans.keySet().size() - passiveMinisters.get(pos) >= k) importantTracks.add(edgeID);
    	
    	return ans;
    	
    }
    
    public static void main(String[] args) throws Exception {
    	initialize();

    	makeBiggestChildDFS(0);
    	
    	DFS(0, -1);
    	
    	Collections.sort(importantTracks);    	
    	
    	System.out.println(importantTracks.size());
    	for(int i = 0; i < importantTracks.size(); ++i) {System.out.print(importantTracks.get(i) + (i+1 != importantTracks.size() ? " " : "\n")); } 
    }
}

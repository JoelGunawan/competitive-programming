
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Stack;

public class Friends 
{
	public static int n; 
	public static int p;
	public static int q; 
	public static ArrayList<ArrayList<Integer>> graph; 
	
	public static ArrayList<Boolean> visited; 
	public static ArrayList<Boolean> in; 
	public static ArrayList<Boolean> undecided; 
	public static Stack<Integer> stack; 
	public static ArrayList<Boolean> out; 
	
	public static void main(String[] args) throws Exception
	{
		String line = null;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		line = br.readLine();

		n = Integer.parseInt(line.split(" ")[0]);
		p = Integer.parseInt(line.split(" ")[1]);
		q = Integer.parseInt(line.split(" ")[2]);
		graph = new ArrayList<ArrayList<Integer>>();
		
		for(int i = 0; i < n; i++)
		{
			ArrayList<Integer> temp = new ArrayList<Integer>();
			line = br.readLine(); 
			String[] split = line.split(" ");
			for(int j = 1; j < split.length; j++)
				temp.add(Integer.parseInt(split[j]));
			graph.add(temp);
		}
		
		//System.out.println(n + " " + p + " " + q);
		//System.out.println(graph);
		long startTime = System.currentTimeMillis();
		
		visited = new ArrayList<Boolean>();
		in = new ArrayList<Boolean>();
		undecided = new ArrayList<Boolean>();
		out = new ArrayList<Boolean>();
		
		for(int i = 0; i < n; i++)
		{
			visited.add(false);
			in.add(false);
			undecided.add(false);
			out.add(false);
		}
		
		stack = new Stack<Integer>(); 
		boolean success = true;
		
		for(int u = 0; u < n && success; u++) 
		{
			for(int i = 0; i < graph.get(u).size(); i++) 
			{
				int v = graph.get(u).get(i);
				boolean foundu = false;
				for(int j = 0; j < graph.get(v).size(); j++) 
				{
					foundu |= (graph.get(v).get(j) == u);
				}
				success &= foundu;
			}
		}
		
		for(int i = 0; i < n; i++) 
		{
			if(!visited.get(i) && !findgroup(i)) 
			{
				success = false;
				break;
			}
		}
		
		if(success) 
			System.out.println("home"); 
		else 
			System.out.println("detention");
		
		long endTime = System.currentTimeMillis();
    // System.out.println("That took " + (endTime - startTime) / 1000.0 + " seconds");
	}
	
	public static int popUndecided()
	{
		int v = stack.pop();
		undecided.set(v, false);
		return v;		
	}

	public static void pushUndecided(int v) 
	{
		undecided.set(v, true);
		stack.push(v);
	}

	public static ArrayList<Integer> freshNeighbors(int v) 
	{
		ArrayList<Integer> ans = new ArrayList<Integer>();
		
		for(int i = 0; i < graph.get(v).size(); i++) 
		{
			int neighbor = graph.get(v).get(i);
			if(!(in.get(neighbor) || undecided.get(neighbor) || out.get(neighbor))) 
				ans.add(neighbor);
		}
		
		return ans;
	}
	
	public static boolean findgroup(int v) 
	{
		pushUndecided(v);
		boolean ans = branchIn(0,0);
		popUndecided();
		visited.set(v, true);
		return ans;
	}
	
	public static boolean mainBranch(int groupSize, int cutSize) 
	{
		if(groupSize > p || cutSize > q || groupSize + cutSize + stack.size() > p+q) 
			return false;
		if(stack.empty()) 
			return true;
		return(branchOut(groupSize, cutSize) || branchIn(groupSize, cutSize));
	}

	public static boolean branchOut(int groupSize, int cutSize) 
	{
		int v = popUndecided();
		out.set(v, true); 
		for(int i = 0; i < graph.get(v).size(); ++i) 
		{
			if(in.get(graph.get(v).get(i)))
				cutSize++;
		}

		boolean ans = mainBranch(groupSize, cutSize);
		out.set(v, false);
		pushUndecided(v);
		return ans;
	}

	public static boolean branchIn(int groupSize, int cutSize) 
	{
		int v = popUndecided();
		in.set(v, true);

		ArrayList<Integer> nv = freshNeighbors(v);
		for(int i = 0; i < nv.size(); ++i) 
			pushUndecided(nv.get(i));
		
		for(int i = 0; i < graph.get(v).size(); ++i) 
		{
			if(out.get(graph.get(v).get(i)))
				cutSize++;
		}
		
		boolean ans = mainBranch(groupSize + 1, cutSize);
		in.set(v, false);
		for(int i = 0; i < nv.size(); ++i) 
			popUndecided();
		pushUndecided(v);

		if(ans)	
			visited.set(v, true);
		return ans;
	}
}

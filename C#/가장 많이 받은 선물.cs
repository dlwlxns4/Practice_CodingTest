using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Collections.Specialized;

public class Solution
{
    public int solution(string[] friends, string[] gifts)
    {
        int answer = 0;

        int[,] sendPointTable = new int[friends.Length, friends.Length];

        Dictionary<string, int> friendIndexPairDic = new Dictionary<string, int>();
        Dictionary<int, int> giftCountDic = new Dictionary<int, int>();
        Dictionary<int, int> nextMonthGiftCount = new Dictionary<int, int>();

        foreach (var friend in friends)
        {
            friendIndexPairDic[friend] = Array.IndexOf(friends, friend);
            giftCountDic[Array.IndexOf(friends, friend)] = 0;
            nextMonthGiftCount[Array.IndexOf(friends, friend)] = 0;
        }
        

        foreach (var giftData in gifts)
        {
            var send = giftData.Split(" ")[0];
            var receive = giftData.Split(" ")[1];

            friendIndexPairDic.TryGetValue(send, out int sendIndex);
            friendIndexPairDic.TryGetValue(receive, out int receiveIndex);

            ++sendPointTable[sendIndex, receiveIndex];

            giftCountDic[sendIndex]++;
            giftCountDic[receiveIndex]--;
        }

        for (int i = 0; i < sendPointTable.GetLength(0); i++)
        {
            for (int j = 0; j < sendPointTable.GetLength(1); j++)
            {
                Console.Write(sendPointTable[i, j] + " ");
            }
            Console.WriteLine();
        }

        foreach(var giftCount in giftCountDic)
        {
            Console.WriteLine($"Friend {friends[giftCount.Key]} has sent {giftCount.Value} gifts.");
        }

        for (int i = 0; i < sendPointTable.GetLength(0); i++)
        {
            for (int j = i; j < sendPointTable.GetLength(1); j++)
            {
                if (i == j)
                    continue;

                if (sendPointTable[i, j] > sendPointTable[j, i])
                {
                    nextMonthGiftCount[i]++;
                }
                else if (sendPointTable[i, j] < sendPointTable[j, i])
                {
                    nextMonthGiftCount[j]++;
                }
                else
                {
                    //선물지수 체크
                    if (giftCountDic[i] > giftCountDic[j])
                    {
                        nextMonthGiftCount[i]++;
                    }
                    else if (giftCountDic[i] < giftCountDic[j])
                    {
                        nextMonthGiftCount[j]++;
                    }
                }
            }
        }


        foreach(var nextMonthGift in nextMonthGiftCount)
        {
            answer = Math.Max(answer, nextMonthGift.Value);
        }

        return answer;
    }
}

internal static class Program
{
    static void Main()
    {
        var s = new Solution();

        TC("1.", s.solution(new string[] { "muzi", "ryan", "frodo", "neo" },
            new string[] { "muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi" }), 2);
        TC("2.", s.solution(new string[] { "joy", "brad", "alessandro", "conan", "david" },
    new string[] { "alessandro brad", "alessandro joy", "alessandro conan", "david alessandro", "alessandro david" }), 4);

        Console.WriteLine("\nDone.");
    }

    static int ToInt(string? x) => int.Parse(x!);

    static int[] ToIntArray(string? line)
        => string.IsNullOrWhiteSpace(line)
           ? Array.Empty<int>()
           : line.Split(new[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries)
                 .Select(ToInt).ToArray();

    static int[] ReadLineArray(TextReader r) => ToIntArray(r.ReadLine());

    static void TC<T>(string name, T actual, T expected)
    {
        bool ok = AreEqualDeep(actual, expected);
        Console.WriteLine($"{name} {(ok ? "[OK]" : "[FAIL]")}");
        if (!ok)
        {
            Console.WriteLine($"Expected: {ToStringDeep(expected)}");
            Console.WriteLine($"Actual  : {ToStringDeep(actual)}");
        }
        Console.Write("\n");
    }

    static bool AreEqualDeep(object? a, object? b)
    {
        if (ReferenceEquals(a, b)) return true;
        if (a is null || b is null) return false;

        if (a is string sa && b is string sb) return sa == sb;
        if (a is double da && b is double db) return Math.Abs(da - db) < 1e-9;
        if (a is float fa && b is float fb) return Math.Abs(fa - fb) < 1e-6;

        if (a is System.Collections.IEnumerable ea && b is System.Collections.IEnumerable eb && a is not string && b is not string)
        {
            var la = ea.Cast<object?>().ToList();
            var lb = eb.Cast<object?>().ToList();
            if (la.Count != lb.Count) return false;
            for (int i = 0; i < la.Count; i++)
                if (!AreEqualDeep(la[i], lb[i])) return false;
            return true;
        }
        return a.Equals(b);
    }

    static string ToStringDeep(object? obj)
    {
        if (obj is null) return "null";
        if (obj is string s) return $"\"{s}\"";
        if (obj is System.Collections.IEnumerable e && obj is not string)
        {
            var items = e.Cast<object?>().Select(ToStringDeep);
            return "[" + string.Join(", ", items) + "]";
        }
        return obj.ToString() ?? "(null)";
    }
}

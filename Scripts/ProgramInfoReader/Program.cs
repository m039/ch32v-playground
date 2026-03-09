using ProgramInfoReader;
using System.Diagnostics;
using System.Text.Json;

var psi = new ProcessStartInfo();
psi.FileName = "minichlink.exe";
psi.Arguments = "-r - flash 16384";
psi.RedirectStandardOutput = true;
psi.RedirectStandardError = true;
psi.UseShellExecute = false;
psi.CreateNoWindow = true;

string output = "";
string error = "";

using (Process process = new Process())
{
    process.StartInfo = psi;
    process.Start();

    output = process.StandardOutput.ReadToEnd();
    error = process.StandardError.ReadToEnd();

    process.WaitForExit();
}

const string prefix = "program_info:{";
ProgramInfo? programInfo = null;

for (int i = 0; i < output.Length; i++)
{
    var index = output.IndexOf(prefix, i);
    if (index != -1)
    {
        var newI = index + prefix.Length;
        var lastBracket = output.IndexOf('}', newI);
        if (lastBracket != -1)
        {
            var str = output.Substring(newI - 1, lastBracket + 1 - (newI - 1));

            programInfo = JsonSerializer.Deserialize<ProgramInfo>(str);
            if (programInfo != null)
            {
                break;
            }
        }
        i = newI;
    } else
    {
        break;
    }
}

if (programInfo == null)
{
    Console.WriteLine("Can't find program info.");
} else
{
    Console.WriteLine("Program Info:");
    Console.WriteLine("  Name: " + programInfo.name);
    Console.WriteLine("  Version: " + programInfo.version);
}
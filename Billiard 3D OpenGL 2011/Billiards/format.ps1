$Extensions = ('*.cpp', '*.hpp')
$Path = ('src', 'inc')
$Excludes = ""
Get-ChildItem -Path $Path -Recurse -Include $Extensions -Exclude $Excludes | ForEach-Object {
    Write-Output "Processing  $($_.FullName)"
    ./clang-format -i $_.FullName
}
Write-Output "Formatting done."

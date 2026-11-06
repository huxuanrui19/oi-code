from pathlib import Path
import shutil
import subprocess

root = Path(r'D:\oi-code\mock_contest20261104')
work = root / '.build' / 'runs'
work.mkdir(parents=True, exist_ok=True)

jobs = []
for name in ('arrange', 'word', 'grid'):
    for src in sorted((root / name / name).glob('*.in')):
        jobs.append((name, src, src.with_suffix('.out')))

samples = {
    'arrange': [
        ('sample1', '3\n2 3 1\n', '3\n'),
        ('sample2', '4\n2 1 4 3\n', '6\n'),
    ],
    'loop': [
        ('sample1', '3 100\n10 50\n30 20\n60 40\n', '0\n'),
        ('sample2', '4 100\n30 70\n10 12\n60 75\n90 50\n', '1\n'),
    ],
}
for name, cases in samples.items():
    for tag, text, expected in cases:
        src = work / f'{name}-{tag}.in'
        out = work / f'{name}-{tag}.out'
        src.write_text(text)
        out.write_text(expected)
        jobs.append((name, src, out))

for name, src, expected in jobs:
    run = work / f'{name}-{src.parent.name}-{src.stem}'
    run.mkdir(exist_ok=True)
    shutil.copyfile(src, run / f'{name}.in')
    exe = root / name / '.build' / 'solution.exe'
    subprocess.run([str(exe)], cwd=run, check=True, timeout=20)
    got = (run / f'{name}.out').read_text().split()
    want = expected.read_text().split()
    if got != want:
        raise AssertionError(f'{name} {src.name}: {got[:5]} != {want[:5]}')
    print('OK', name, src.parent.name, src.name)

clear all;
% Configuration parameters input by user
nlist = [ 5, 7, 10 ];
dlist = [ 0:5 ];

% Setup the parent directory for saving generated files
parentdir = sprintf('%s/apps/LightControl/topology/comm', getenv('TOSROOT'));

for ns = 1:length(nlist)
    n = nlist(ns); % N = n x n grid of sensors
    for ds = 1:length(dlist)
        degree = dlist(ds); % Controls actuator influence region
        
        % Generate adjacency graph from actuation model
        filename = sprintf('%s/adj_%d_d%d.txt', parentdir, n, degree);
        Adj = load(filename);
        D = sum(Adj);

        % Generate the metropolis weights and write them to file
        W = zeros(size(Adj, 1));
        for i = 1:size(Adj, 1)
            % Find neighboring nodes in adjacency matrix
            nodes = find(Adj(i,:));
            if (length(nodes) == 0)
                continue
            end
            % Assign Wij for each edge (i,j) in adjacency matrix
            sum_Wik = 0;
            for j = 1:length(nodes)
                if (i == nodes(j))
                    continue
                end
                w = 1 / ( 1 + max(D(i),D(nodes(j))) );
                W(i, nodes(j)) = w;
                sum_Wik += w;
            end
            W(i, i) = 1 - sum_Wik;
        end
        filename = sprintf('%s/metweights_%d_d%d.h', parentdir, n, degree);
        fid = fopen(filename, 'w');
        fprintf(fid, '#ifndef _MET_WEIGHTS_H_\n');
        fprintf(fid, '#define _MET_WEIGHTS_H_\n\n');
        fprintf(fid, 'float W(uint16_t n1) {\n');
        indent = 1;
        tabs = get_indent(indent);
        fprintf(fid, '%sfloat a = 0;\n', tabs);
        fprintf(fid, '%sswitch (TOS_NODE_ID) {\n', tabs);
        indent += 1;
        for i = 1:size(W, 1)
            nodes = find(W(i,:));
            if ( length(nodes) == 0 )
                continue
            end
            fprintf(fid, '%scase %d: {\n', get_indent(indent), i-1);
            indent += 1;
            fprintf(fid, '%sswitch (n1) {\n', get_indent(indent));
            indent += 1;
            for j = 1:length(nodes)
                fprintf(fid, '%scase %d: a=%f; break;\n', ...
                             get_indent(indent), ...
                             nodes(j)-1, W(i, nodes(j)));
            end
            fprintf(fid, '%sdefault: break;\n', get_indent(indent));
            indent -= 1;
            fprintf(fid, '%s}\n', get_indent(indent));
            fprintf(fid, '%sbreak;\n', get_indent(indent));
            indent -= 1;
            fprintf(fid, '%s}\n', get_indent(indent));
        end
        fprintf(fid, '%sdefault: break;\n', get_indent(indent));
        indent -= 1;
        fprintf(fid, '%s}\n', get_indent(indent));
        fprintf(fid, '%sreturn a;\n}\n\n', get_indent(indent));
        fprintf(fid, '#endif\n');
        fclose(fid);

    end
end

